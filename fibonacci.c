#include <stdio.h>
#include <stdlib.h>

int main () {
	
	int i=2, n;
	long long num=1;
	
	system("clear");
	
	printf("Indique um número ");
	scanf("%d", &n);
		
	long long *vetor;
	vetor = (long long *)malloc(n*sizeof(long long));

	vetor[0]=0;
	vetor[1]=1;
	printf("i:0 num:%lld\ni:1 num:%lld\n", vetor[0], vetor[1]);
	for(i = 2; i<n; i++){		
		num=vetor[i-1]+vetor[i-2];
		if(num == vetor[i-1]+vetor[i-2]){
			vetor[i]=num;
			printf("i:%d num:%lld\n", i, vetor[i]);
		}
	}
	
	return (0);
}