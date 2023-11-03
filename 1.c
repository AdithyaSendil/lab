


#include<stdio.h>
#include<time.h>
int a[10][10],visited[10],n,cost=0;
mincost(int city)
{
	int i,ncity;
	visited[city]=1;	
	printf("%d -->",city+1);
	ncity=least(city);
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity);
}

int least(int c)
{
	int i,nc=999;
	int min=999;
	for(i=0;i<n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
			if(a[c][i] < min)
			{
				min=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=min;
	return nc;
}

main()
{
        int i,j;
        double clk;
        clock_t starttime,endtime; 
	printf("Enter No. of Cities: ");
	scanf("%d",&n);
	printf("\n Enter Cost Matrix\n");
	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row # : %d\n",i+1);
		for( j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		visited[i]=0;
	}

	printf("\n\nThe cost list is:\n\n");
	for( i=0;i < n;i++)
	{
		printf("\n\n");
		for(j=0;j < n;j++)
			printf("\t%d",a[i][j]);
	}
	printf("\n\nThe Path is:\n\n");
            starttime=clock();
            mincost(0);
            endtime=clock();
            clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("\n\nMinimum cost:%d\n",cost);
        printf("\nThe run time is %f\n",clk); 
}

prg 2

#include<stdio.h>
#include<time.h>
void bfs(int a[10][10],int n,int source)
{
 	int s[10],q[10],f=0,r=-1,t,v;
	 for(v=0;v<n;v++)
	{
		s[v]=0;
	}
 	q[++r]= source;
 	s[source]=1;
	while(f<=r)
 	{
  		t=q[f++];
  		for(v=0; v<n; v++)
		if(a[t][v]==1 && s[v]==0)
		{
	 		q[++r]=v;
	 		printf("The BFS traversal is:\n %d %d", t, v);
	 		s[v]=1;
		}
 	}
  }


main()
{
 	int a[10][10],n,i,j,s;
      double clk;
      clock_t starttime,endtime;
	printf("\n Enter the number of vertices\n");
 	scanf("%d",&n);
	printf("\nEnter the matrix represention:");
 	for(i=0;i<n;i++)
 	for(j=0;j<n;j++)
  	scanf("%d",&a[i][j]);
 	printf("\nEnter the source vertix");
 	scanf("%d",&s);
      starttime=clock(); 
 	bfs(a,n,s);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
      printf("\nThe run time is %f\n",clk);
 
}

pgr 3
#include<stdio.h>
#include<time.h>
int n,a[50][50],i,j,count=0,reach[50],pos[50];
int main()
{
        int v;
        double clk;
        clock_t starttime,endtime;
        printf("\n\t\t\t DEPTH FIRST SEARCH \n");
        printf("\n Enter number of verteces:");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
       {	
          	pos[i]=0;
       }
        read_matrix();
        printf("\n Enter the starting vertex:");
        scanf("%d",&v);
        starttime=clock();
        dfs(v);
        endtime=clock();
        clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
        printf("\n Vertices reached from the given vertex are...\n");
       for(i=1;i<=count;i++)
       {
	printf("%d\t",reach[i]);
       }
        printf("\nThe run time is %f\n",clk);
}

read_matrix()
{
	printf("\n Enter the adjacency matrix (Enter 0/1)\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i!=j)
	{
		printf("(%d,%d):",i,j);
		scanf("%d",&a[i][j]);
	}
}

dfs(int v)
{
	int u;
	reach[++count]=v;
	u=adjacent(v);
	while(u)
	{
		if(checkreach(u)==0) dfs(u);
		u=adjacent(v);
	}
}
adjacent(int i)
{
	for(j=pos[i]+1;j<=n;j++)
	if(a[i][j]==1)
	{
		pos[i]=j;
		return j;
	}
	pos[i]=n+1;
	return 0;
}
checkreach(int u)
{
	for(i=1;i<=count;i++)
	if(reach[i]==u)
		return 1;
	return 0;
}

pgr 4

#include<stdio.h>
#include<time.h>
int a[500000];
void merge(int,int,int);
void merge_sort(int low,int high)
{
	 int mid;
	 if(low<high)
	 {
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
 	}
}
void merge(int low,int mid,int high)
{
	 int h,i,j,b[500000],k;
	 h=low;
	 i=low;
	 j=mid+1;
	 while((h<=mid)&&(j<=high))
	{
		  if(a[h]<=a[j])
		{
			   b[i]=a[h];
			   h++;
		}
		else
		{
			b[i]=a[j];
			 j++;
  		}
  		i++;
 	}
 	if(h>mid)
 	{
  		for(k=j;k<=high;k++)
  		{
   			b[i]=a[k];
   			i++;
  		}
	}
 	else
 	{
  		for(k=h;k<=mid;k++)
  		{
   			b[i]=a[k];
  			 i++;
  		}
 	}
	for(k=low;k<=high;k++) a[k]=b[k];
}

int main()
{
 	int n,i;
 	double clk;
 	clock_t starttime,endtime;
 	printf("MERGE SORT\n");
 	printf("Enter the number of employee records:\n ");
 	scanf("%d",&n);
 	 for(i=0;i<n;i++) 
       	{
        		 a[i]=rand()%100;
         		printf("The Employee IDs are: \t%d",a[i]);
        	}
	 starttime=clock(); 
	 merge_sort(1,n);
 	endtime=clock();
 	clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 	printf("\nEmployee IDs in sorted order:\n");
 	for(i=1;i<=n;i++) 
  	{
   		printf("\t%d",a[i]);
 	}
	printf("\nThe run time is %f\n",clk);
}

pgr 5

#include<stdio.h>
#include<time.h>
int partition(int a[],int low,int high)
{
	int i,j,temp,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(i<high&&a[i]<=pivot)
		i++;
		while(a[j]>pivot)
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[j];
			a[j]=a[low];
			a[low]=temp;
			return j;
		}
	}
}

 quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

main()
{
	int i, n,a[200000];
      double clk;
      clock_t starttime,endtime;
	printf("Enter the number of students records: \n");
	scanf("%d",&n);
       for(i=0;i<n;i++) 
       {
        	 a[i]=rand()%100;
         	printf("The roll numbers are \t%d",a[i]);
        }
        starttime=clock();
	quick_sort(a,0,n-1);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("\nSorted roll numbers are: \n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
      printf("\nThe run time is %f\n",clk);
}

pgr 6

#include<stdio.h>
#include<time.h>
#define TRUE
#define FALSE

void heapbottomup(int h[],int n)
{
   	int i,heap,v,j,k;
   	for(i=n/2;i>0;i--)
	{
		k=i;
		v=h[k];
		heap=FALSE;
		while(!heap && (2*k)<=n)
		{
			j=2*k;
			if(j<n)
   	  		if(h[j]<h[j+1])
			j=j+1;
      		if(v>=h[j])
			heap=TRUE;
			else
			{
				h[k]=h[j];
				k=j;
			}
	}
}

void heapsort(int h[],int n)
{    
	int i,temp,last=n;
	if(n<=1)
      return;
     else
   {
		heapbottomup(h,n);
		temp=h[last];
		h[last]=h[1];
		h[1]=temp;
		last--;
      	heapsort(h,n-1);
	}
}

main()
{
	int h[20],n,i;
	double clk;
      clock_t starttime,endtime;
	printf("\n Enter the number of resumes\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
       {
	         h[i]=rand()%100;
               printf("The candidates ranks are: \t%d",h[i]);
        }
        starttime=clock();
	  heapsort(h,n);
        endtime=clock();
        clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	  printf("\n The ranks in sorted order: \n");
	  for(i=1;i<=n;i++)
	  printf("\t%d",h[i]);
        printf("\nThe run time is %f\n",clk);

}

pgr 7

#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];
void shifttable(char p[])
{
 int i,j,m;
 m=strlen(p);
 for(i=0;i<MAX;i++)
  t[i]=m;
 for(j=0;j<m-1;j++)
  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[])
{
 int i,j,k,m,n;
 n=strlen(src);
 m=strlen(p);
 printf("\nLength of text=%d",n);
 printf("\n Length of pattern=%d",m);
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==src[i-k]))
   k++;
  if(k==m)
   return(i-m+1);
  else
   i+=t[src[i]];
 }
}
void main()
{
 char src[100],p[100];
 int pos;
 clrscr();
 printf("Enter the text in which pattern is to be searched:\n");
 gets(src);
 printf("Enter the pattern to be searched:\n");
 gets(p);
 shifttable(p);
 pos=horspool(src,p);
 if(pos>=0)
  printf("\n The desired pattern was found starting from position %d",pos+1);
 else
  printf("\n The pattern was not found in the given text");
}

pgr 8

#include<stdio.h>
#include<time.h>
int main()

{
    int a[10][10];
    inti,j,k,n;
   doubleclk;
   clock_t starttime,endtime;
   printf("Enter  number of vertices:");
   scanf("%d",&n);
   printf("Enter the adjacency matrix");
   for(i=0;i<n;i++)

         {
            for(j=0;j<n;j++)

             {
                scanf("%d",&a[i][j]);

            }

         }
starttime=clock();
for(k=1;k<n;k++)

       {
           for(i=1;i<n;i++)

              {
                    for(j=1;j<n;j++)
                      {
                           a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);

                        }

                 }

            }
    endtime=clock();
printf(“The transitive closure of the digraph is:\n”);   
for(i=0;i<n;i++)

       {
          for(j=0;j<n;j++)

             {
                printf("%d",a[i][j]);
             }

           printf("\n");

        }
   clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
   printf("The runtime is %f",clk);

}

pgr 9

#include<stdio.h>
#include<time.h>
double clk;
clock_t starttime,endtime;

int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

void floyd(int n,int W[10][10],int D[10][10])
{
   	int i,j,k;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	D[i][j]=W[i][j];
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
			}
		}
	}
}

void main()
{
	int i,j,n,D[10][10],W[10][10];
	printf("Enter no.of vertices: \n");
	scanf("%d",&n);
	printf("Enter the cost matrix: \n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&W[i][j]);
	starttime=clock();
            floyd(n,W,D);	
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 printf("All pair shortest path matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",D[i][j]);
		}
	}
   printf("\nThe run time is %f\n",clk);
}

pgr 10

#include<stdio.h>
#include<time.h>
int max(intx,int y)
{
   return((x>y)?x:y);
}
int knap(intn,int w[10],int value[10],intm,int v[10][10])
{
   inti,j;
   for(i=0;i<=n;i++)
   for(j=0;j<=m;j++)
    {
      if(i==0||j==0)
        v[i][j]=0;
      else if(j<w[i])
        v[i][j]=v[i-1][j];
      else
        v[i][j]=max(v[i-1][j],value[i]+v[i-1][j-w[i]]);
     }
    printf("\n The table for solving knapsack problem using dynamic programming is:\n");
    for(i=0;i<=n;i++)
     {
      for(j=0;j<=m;j++)
        {
         printf("%d\t",v[i][j]);
         }
      printf("\n");
    }
}
main()
{
  doubleclk;
  clock_tstarttime,endtime;
  int v[10][10],n,i,j,w[10],value[10],m,result;
  printf("Enter the number of items:");
  scanf("%d",&n);
  printf("Enter the weights of %d items:/n",n);
  for(i=1;i<=n;i++)
   {
     scanf("%d",&w[i]);
   }
   printf("Enter the value of %d items:",n);
   for(i=1;i<=n;i++)
   {
     scanf("%d",&value[i]);
   }
   printf("Enter the capacity of the knapsack:");
   scanf("%d",&m);
   for(i=0;i<=n;i++)
   {
      for(j=0;j<=m;j++)
      {
         v[i][j]=0;
      }
   }
  starttime=clock();
  result=knap(n,w,value,m,v);
  endtime=clock();
  clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
  printf("Optimal solution for the knapsack problem is %d\n",v[n][m]);
  printf("%f\n",clk);
}

pgr 11

#include<stdio.h>
#include<time.h>
int min(inta,int b)
{
    return((a<b)?a:b);
}
void prims(intn,int cost[10][10])
{
    inti,j,k,u,v,min,source;
   intsum,t[20][20],p[10],d[10],visited[10];
   min=9999;
   source=0;
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       if(cost[i][j]!=0&&cost[i][j]<=min)
        {
min=cost[i][j];
source=i;
        }
    for(i=0;i<n;i++)
    {
        d[i]=cost[source][i];
        visited[i]=0;
        p[i]=source;
    }
visited[source]=1;
sum=0;
k=0;
for(i=1;i<n;i++)
{
    min=9999;
    u=-1;
   for(j=0;j<n;j++)
    {
       if(visited[j]==0)
       {
           if(d[j]<=min)
               {
                 min=d[j];
                 u=j;
                }
          }
    }
t[k][0]=u;
t[k][1]=p[u];
k++;
sum=sum+cost[u][p[u]];
visited[u]=1;
   for(v=0;v<n;v++)
    {
           if(visited[v]==0&&cost[u][v]<d[v])
           {
                 d[v]=cost[u][v];
                  p[v]=u;
           }
    }
}
if(sum>=9999)
    printf("\n Spanning tree does not exist");
else
   {
        printf("Spanning tree exists and minimum spanning tree is\n");
        for(i=0;i<n-1;i++)
          {
               printf("%d  %d\n",t[i][0],t[i][1]);
          }
         printf("\n The cost of spanning tree is %d ",sum);
    }
}
int main()
{
int cost[10][10],n,i,j;
doubleclk;
clock_tstarttime,endtime;
printf("Enter the number of vertices :");
scanf("%d",&n);
printf("Enter the cost adjacency matrix :");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
starttime=clock();
prims(n,cost);
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("The time taken is %f\n",clk);
}

pgr 12

#include<stdio.h>
#include<time.h>
struct edge
{
     intu,v,cost;
};
typedefstruct edge edge;
int find(intv,int parent[])
{
    while(parent[v]!=v)
     {
       v=parent[v];
     }
   return v;
}
voidunion_ij(inti,intj,int parent[])
{
     if(i<j)
       parent[j]=i;
    else
       parent[i]=j;
}
voidkruskal(intn,edge e[],int m)
{
     intcount,k,i,sum,u,v,j,t[10][10],p,parent[10];
     edge temp;
     count=0;
     k=0;
    sum=0;
   for(i=0;i<m;i++)
    {
       for(j=0;j<m-1;j++)
        {
            if(e[j].cost>e[j+1].cost)
              {
temp.u=e[j].u;
temp.v=e[j].v;
temp.cost=e[j].cost;
e[j].u=e[j+1].u;   
e[j].v=e[j+1].v;
e[j].cost=e[j+1].cost;
e[j+1].u=temp.u;
e[j+1].cost=temp.cost;
                }
          }
    }
   for(i=0;i<n;i++)
   parent[i]=i;
   p=0;
   while(count!=n-1)
    {
u=e[p].u;
v=e[p].v;
i=find(u,parent);
j=find(v,parent);
if(i!=j)
{
t[k][0]=u;
t[k][1]=v;
k++;
count++;
sum+=e[p].cost;
union_ij(i,j,parent);
}
           p++;
    }
 if(count==n-1)
    {
printf("Spanning tree exists\n");
printf("The spanning tree is as follows:\n");
for(i=0;i<n-1;i++)
              {
                  printf("%d  %d\t",t[i][0],t[i][1]);
              }
           printf("\nThe cost of the spanning tree is %d\n",sum);
     }
else
      printf("\n spanning tree does not exist");
}
void main()
{
intn,m,a,b,i,cost;
double clk;
clock_t starttime,endtime;
edge e[20];
printf("Enter the number of vertices:");
scanf("%d",&n);
printf("Enter the number of edges:\n");
scanf("%d",&m);
printf("Enter the edge list( u  v  cost)\n");
for(i=0;i<m;i++)
{
scanf("%d%d%d",&a,&b,&cost);
e[i].u=a;
e[i].v=b;
e[i].cost=cost;
}
starttime=clock();
kruskal(n,e,m);
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("The time taken is %f\n",clk);
  }

pgr 13

#include<stdio.h>
#include<time.h>

#define MAX 10

int choose(int dist[],int s[],int n)
{
  int j=1,min=100,w;
  for(w=1;w<=n;w++)
   if((dist[w]<min) && (s[w]==0))
     {
       min=dist[w];
       j=w;
     }
   return j;
}

void spath(int v,int cost[][MAX],int dist[],int n)
 {
    int w,u,i,num,s[MAX];
    for(i=1;i<=n;i++)
     {
        s[i]=0;
          dist[i]=cost[v][i];
        }
     s[v]=0;
     dist[i]=999;
     for(num=2;num<=n;num++)
      {
        u=choose(dist,s,n);
        s[u]=1;
       for(w=1;w<=n;w++)
       if((dist[u]+cost[u][w])<dist[w] && !s[w])  
            dist[w]=dist[u]+cost[u][w];  
        } 
 }

void main()
{
   int i,j,cost[MAX][MAX],dist[MAX],n,v;
   double clk;
   clock_t starttime,endtime;

   printf("\nEnter number of vertices:");
   scanf("%d",&n);
   printf("\nEnter the cost of adjacency matrix\n");
  for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
       scanf("%d",&cost[i][j]);
  printf("\nEnter the source vertex");
  scanf("%d",&v);

  starttime=clock();
  spath(v,cost,dist,n);
  endtime=clock();
  printf("\nShortest  distance\n");
  for(i=1;i<=n;i++)
       printf("\n%d to %d = %d",v,i,dist[i]);
       clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
       printf("The time taken is %f\n",clk);

}
Expected output:
Enter the number of vertices : 5
Enter the cost of adjacency matrix
999	4	2	999	8
999	999	999	4	5
999	999	999	1	999
999	999	999	999	3
999	999	999	999	999

Enter the source vertex : 1
Shortest  distance
1 to 1 = 0
1 to 2 = 4
1 to 3 = 2
1 to 4 = 3
1 to 5 = 6
The time taken is 0.456643


⦁	Design and develop a program in C to implement n/Queens problem by using backtracking method.

Aim:	Place the n-queens on the chess board using the backtracking methodology

Theory: Backtracking is a more intelligent variation.The principal idea is to construct solutions one component at a time and evaluate such partially constructed candidates as follows. If a partially constructed solution can be de-veloped further without violating the problem’s constraints, it is done by taking the first remaining legitimate option for the next component. If there is no legiti-mate option for the next component, no alternatives for any remaining component need to be considered. In this case, the algorithm backtracks to replace the last component of the partially constructed solution with its next option.

The n-queens problem. The problem is to place n queens on an n × n chessboard so that no two queens attack each other by being in the same row or in the same column or on the same diagonal. For n = 1, the problem has a trivial solution, and it is easy to see that there is no solution for n = 2 and n = 3.
Algorithm design technique

Step 1:    Start with the empty board and then place queen 1 in the first possible position of its row, which is in column 1 of row 1. 

Step 2:Then we place queen 2, after trying unsuccessfully columns 1 and 2, in the first acceptable position for it, which is square (2, 3), the square in row 2 and column 3. This proves to be a dead end because there is no acceptable position for queen 3. So, the algorithm backtracks and puts queen 2 in the next possible position at (2, 4). 

Step 3 :Then queen 3 is placed at (3, 2), which proves to be another dead end. The algorithm then backtracks all the way to queen 1 and moves it to (1, 2). Queen 2 then goes to (2, 4), queen 3 to (3, 1), and queen 4 to (4, 3), which is a solution to the problem.    

PROGRAM:

//backtracking
#include<stdio.h>
#include<math.h>
#define FALSE 0
#define TRUE 1

int x[20];
int place(int k,int i)
{
	int j;
	for(j=1;j<=k;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		return FALSE;
	}
return TRUE;
}

void nqueens(int k,int n)
{
	int i,a;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				for(a=1;a<=n;a++)
					printf("%d\t",x[a]);
				printf("\n");
			}
			else
			nqueens(k+1,n);
		}
	}
}
void main()
{
	int n;
	printf("\nEnter the number of queens:");
	scanf("%d",&n);
	printf("\n The solution to N Queens problem is: \n");
	nqueens(1,n);
}

pgr 14

#include<stdio.h>
  
int count,w[10],d,x[10];
  
void subset(int cs,int k,int r)
{
   int i;
   x[k]=1;
   if((cs+w[k])>d)
    {
       printf("\n Subset solution = %d\n",++count);
       for(i=0; i<=k; i++)
       {
         if(x[i]==1)
         printf("%d\n",w[i]);
       }
     }
  else if(cs+w[k]+w[k+1] <=d)
        subset(cs+w[k],k+1,r-w[k]);
    if((cs+r-w[k]>=d)&&(cs+w[k+1])<=d)
    {               
      x[k]=0;
      subset(cs,k+1,r-w[k]);
    }
}
  
int main()
{
    int sum=0,i,n;
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("Enter the elements in ascending order\n");
    for(i=0; i<n; i++)
    scanf("%d",&w[i]);
    printf("Enter the required sum\n");
    scanf("%d",&d);
    for(i=0; i<n; i++)
    sum +=w[i];
 if(sum < d)
    {
        printf("no solution exits\n");
          
    }   
    printf("The solution is\n");
    count =0;
    subset(0,0,sum);
    return 0;
    getch();
}
