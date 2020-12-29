#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define sampling 1000
#define total_neurons 1000
#define total_time 10000

double LIF(int i, double u[], double uth, double mu, double sigma_nl, double sigma_diag, int R_nl, int R_diag)
{
	//!!it must be total_neurons > 2*(R_diag + R_nl) + 1!!; 
	double sum=0,sum_diag=0,sum_nl=0;
	int j,nn;
	int diag;
	nn = 2 * R_diag + 2 * R_nl + 1;
	diag = total_neurons/2 + i;
	
	for (j=1; j<=R_diag; j++) 
		sum_diag += (u[(diag+j)%total_neurons] - u[i]) + (u[(diag-j+total_neurons)%total_neurons] - u[i]);
	sum_diag += u[diag%total_neurons]-u[i];

	for (j=1; j<=R_nl; j++) 
		{
			sum_nl += (u[(i+j)%total_neurons] - u[i]) + (u[(i-j+total_neurons)%total_neurons] - u[i]);
		}
	
	sum = sigma_diag*sum_diag + sigma_nl*sum_nl;
	
	
	return (mu - u[i] - sum / nn);	
}

int main(int argc, char *argv[])
{
	if (argc!=2)
	{
		printf("Usage: ./lif_nonlocal_diagonal outputfile\nsigma_diag\nsigma_nl\nR_diag\nR_nl\nseed\n");
		exit(1);
	}
	FILE *fp;
	fp=fopen(argv[1],"w");
	
	double u[total_neurons],u_[total_neurons],uth,mu,dt,t;
	float sigma_diag,sigma_nl;
	float omega[total_neurons];
	int R_nl,R_diag,i;
	int print_flag,seed;
	pid_t p;
	
	int scart = scanf("%f",&sigma_diag);
	if (scart!=1) exit(1);
	
	scart = scanf("%f",&sigma_nl);
	if (scart!=1) exit(1);
	
	scart = scanf("%d",&R_diag);
	if (scart!=1) exit(1);
	
	scart = scanf("%d",&R_nl);
	if (scart!=1) exit(1);
	
	scart = scanf("%d",&seed);
	if (scart!=1) exit(1);
	
	uth = 0.98;
	mu = 1;
	dt = 0.001;
	srand(seed);
	t=0;
	
	print_flag=sampling;
	//initialiazations
	for(i = 0; i<total_neurons; i++) 
	{
		omega[i]=0;
		u[i] = uth*rand() / RAND_MAX;
	}
	p=fork();
	if(p==0)
	{
		for(i = 0; i<total_neurons; i++) fprintf(fp,"%d\t%f\t%f\t%f\n",i,u[i],t,omega[i]);
		exit(0);
	}
	
	for (t=dt; t<=total_time; t+=dt)
	{
		for(i = 0; i<total_neurons; i++) 
			{ u_[i] =LIF(i,u,uth,mu,sigma_nl,sigma_diag,R_nl,R_diag); }
		for(i = 0; i<total_neurons; i++) 
		{
			u[i] = u[i] + dt*u_[i];
			if(u[i] >= uth)
			{
				omega[i] += 1.0/(sampling*dt);
				u[i] = 0 ;
			}
			if(u[i] <=0) u[i] = 0;
		}
		
		if(--print_flag==0)
		{
			wait(NULL);
			p=fork();
			if(p==0)
			{
				//printf("\r%0.3f%%", t / total_time *100);
				for(i = 0; i<total_neurons; i++) fprintf(fp,"%d\t%f\t%f\t%f\n",i,u[i],t,omega[i]);
				exit(0);
			}
			memset(omega, 0, sizeof(omega));
			print_flag = sampling;
		}
	}
	fclose(fp);
	wait(NULL);
	printf("\n");
	return 0;
}

