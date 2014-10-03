#include <stdio.h>

int M;
int K;
int seed;


FILE *fpi,*fpo;

main(int argc, char *argv[]) {
        int i,j,k;
        int count;
	int w;

        if (argc != 3) {
                printf("Usage: Commandname <inputfile> <outputfile>\n");
                exit(0);
        }
        fpi = fopen(argv[1],"r");
	fpo = fopen(argv[2],"w");

	fscanf(fpi, "%d %d", &M, &K, &seed);
	srandom(seed);

	fprintf(fpo,"%d\n",M);

	for (i=1;i<=M;i++) {
		fprintf(fpo,"%d ", random()%K+1);
		fprintf(fpo,"%d\n",random()%K+1);
	}

}







	
