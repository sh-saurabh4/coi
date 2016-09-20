#include<stdio.h>
#include<malloc.h>

FILE *fp;
FILE *fwx,*fwn,*fr;
struct node{
	int n;
	int x;
	int y;
	struct node *next;
	};

int max(struct node *s,struct node *m,struct node *e){
	struct node* p1;
	int t=1;
	p1=m->next;
	while(s!=m){
		if((s->x)>=(m->x)||(p1->x)>=(m->x))
		t=0;
		s=s->next;
		p1=p1->next;
	}
	return t;
}

int min(struct node *s,struct node *m,struct node *e){
	struct node* p1;
	int t=1;
	p1=m->next;
	while(s!=m){
		if((s->x)<=(m->x)||(p1->x)<=(m->x))
		t=0;
		s=s->next;
		p1=p1->next;
	}
	return t;
}

int main()
{

	int w,t,d,maxc=0,minc=0,c,temp1=-1,temp2=-1,range;
	struct node *p,*q,*s,*m,*e;

	fp = fopen("check2.txt","r");
	fwx = fopen("maxdistance.txt","w");
	fwn = fopen("mindistance.txt","w");
	fr = fopen("range.txt","w");
	printf("*******ENTER THE WINDOW SIZE****************\n");
	fscanf(stdin,"%d",&w);
	printf("*******ENTER THE BIN SIZE OF HISTOGRAM*********\n");
	fscanf(stdin,"%d",&range);
	fprintf(fr,"%d\n",range);
	fclose(fr);
	//printf("%d",w);
	//fun(fp);
	if(w % 2 == 0){
		w = w-1;
	}
	t=w-1;
	d=(w-1)/2;
	p=(struct node *)malloc(sizeof(struct node));
	fscanf(fp,"%d%d%d",&(p->n),&(p->x),&(p->y));
	p->next=NULL;
	q=p;
	s=p;

	while(t){
		p=(struct node *)malloc(sizeof(struct node));
		fscanf(fp,"%d%d%d",&(p->n),&(p->x),&(p->y));
		q->next=p;
		p->next=NULL;
		q=p;

		if(t==1)
			e=p;
		if(t==d+1)
			m=p;
		t--;
	}
	/*
	q=s;
	while(q!=NULL){
		printf("%d %d\n",q->n,q->x);
		q=q->next;
	}
	*/
	do{
		t=max(s,m,e);

		if(t){
			if(temp1 == -1 ){
				temp1 = m->n;
			}
			else{
				fprintf(fwx,"%d\n",(m->n)-temp1);
				temp1 = m->n;
			}
			//printf("local maxima %d %d\n",m->n,m->x);
			maxc++;
		}
		else{
			t=min(s,m,e);
			if(t){
				if(temp2 == -1)
					temp2 = m->n;
				else{
					fprintf(fwn,"%d\n",(m->n)-temp2);
					temp2 = m->n;
				}
				//printf("local minima %d %d\n",m->n,m->x);
				minc++;
			}

		}
		p=(struct node *)malloc(sizeof(struct node));
		c=fscanf(fp,"%d%d%d",&(p->n),&(p->x),&(p->y));
		e->next=p;
		s=s->next;
		m=m->next;
		e=e->next;
	}while(c!=EOF);

	printf("total maxima=%d\n",maxc);
	printf("total minima=%d\n",minc);
	//printf("%d %d %d\n",s->x,m->x,e->y);
	
	system("python plot.py");
	


	fclose(fp);
	fclose(fwx);
	fclose(fwn);

	return 0;
}



