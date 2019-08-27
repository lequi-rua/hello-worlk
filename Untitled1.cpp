#include <studio.h>

int T[Max][Max],G[Max],P[Max],H[Max],F[Max],Open[Max],Close[Max],n,s,g;

int Init_Graph(char *path_graph, char *path_vertex){
	FILE *fptr;
	if(!fptr = fopen(path_graph,"r")))
	return 0;
	fscanf(fptr,"%d%d%d",&n,&s,&g);
	int i,j,x;
	while(fscanf(fptr,"%d%d%d",&i,&j,&x)!=EOF)T[i][j] = T[j][i]=x;
	fclose(fptr);
	double hueristic;
	if(!(fptr = fopen(path_vertex,"r")))
	return 0;
	while (fscanf(fptr,"%d%d%d",&i,&x)!=EOF)H[j]=x;
	fclose(fptr);
	return 1;
	}
int A_Star(int s, int g){
	int u,v;
	Open[s]=1;
	P[s] = s; G[s] = 0;F[s] = G[s] + H[s];
	while(!Empty_Open(Open,n)){
		int max = 32767 ,u;
		for(u = 1;u<=n;u++){
			if(Open[u]==1 && Close[u]==0 && F[u]<max){
				v=u;max=F[u];
				if(v==g) return G[g];
		}
	}
	for(u =1;u<=n;u++)
	if(T[v][u]!=0){
		if(Open[u==0] && Close[u]==0){
			G[u] = G[v] + T[v][u];
			F[u] = G[u] + H[u];P[u]=v;
			Open[u]=1;
			}
			if(Open[u]==1 && && Close[u]==0){
				if(G[v]+T[v][u]<G[u]){
					G[u] = G[v]+T[v][u];
					P[u]=v;
				}
			}
			if(Open[u]==0 && Close[u]==1){
				if(G[v]+T[v][u]<G[u]){
					G[u] = G[v]+T[v][u];
					P[u]=v;
					Close[u]=0;
					Open[u]=1;
				}
			}
		}
		Close[v] =1;
	}
	if(G[g] != 0) return G[g];
	return 0;
}
int main(int argc, char** argv){
	View_Graph(T,n);
	int length = A_Star(s,g);
	printf("\nLength: %d",length);
	return 0; 
}
