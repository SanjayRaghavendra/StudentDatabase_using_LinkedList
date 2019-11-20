/*the following code gives a linked list implementation to store a student database with all the possible operrations 
Authors Shavin K & Sanjay R
Date : 16/11/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	char name[20];
	char usn[10];
	int marks1,marks2,marks3;
	int total,max;
	char grade;
	float attendance;
	struct node *link;
};
typedef struct node *listptr;

void insert(listptr *f, char a[], char b[], int, int, int,float);
void display(listptr f);
void delete(listptr *f);
listptr search(listptr f);
void deleteA(listptr *f);
void bubbleSort(listptr f);
void swap(listptr a,listptr b);
void displayt(listptr f);

int main(){
	int n,i, marks1, marks2, marks3,ch;
	float attendance;
	char usn[20], name[20],n12[20];
	listptr first = NULL;
	printf("enter the number of students\n");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("enter the USN, name, marks1, marks2, marks3 ,attendance of student %d\n", i+1);
		scanf("%s%s%d%d%d%f", usn, name, &marks1, &marks2, &marks3,&attendance );
		insert(&first,usn, name, marks1, marks2, marks3,attendance);
       }
    while(1){
    	printf("Enter 1 to add,2 to delete,3 to dislay,4 to delete particular condition node,5 to sort, 6 to display highest\n");
    	scanf("%d",&ch);
    	switch(ch){
    		case 1:printf("enter the USN, name, marks1, marks2, marks3,attendance of student %d\n");
		           scanf("%s%s%d%d%d%f", usn, name, &marks1, &marks2, &marks3,&attendance );
		           insert(&first,usn, name, marks1, marks2, marks3,attendance);
		            
		            break;
		    case 2: delete(&first);
					  break;
			case 3: 	printf("USN\tNAME\tmarks1\tmarks2\tmarks3\ttotal\tgrade\tattendance\n");
						printf("------------------------------------------------------------\n");
					display(first);
			        break; 
			case 4: 
					deleteA(&first);
						printf("USN\tNAME\tmarks1\tmarks2\tmarks3\ttotal\tgrade\tattendance\n");
						printf("-----------------------------------------------------------\n");
			       display(first);
			   	
			       break;	
			case 5:	//bubbleSort(first);
			   	    break;
			case 6: 	printf("USN\tNAME\tmarks1\tmarks2\tmarks3\ttotal\tgrade\tattendance\n");
						printf("-----------------------------------------------------------\n");
					displayt(first);
			       break;		      
		}
	}
	return 0;

}

void insert(listptr *first, char a[], char b[], int m1, int m2, int m3,float z){
	int i;
	listptr new = (listptr)malloc(sizeof(struct node));
	strcpy(new->usn, a);
	strcpy(new->name, b);
	new->marks1 = m1;		
	new->marks2 = m2;
	new->marks3 = m3;
	new->attendance=z;
	new->link = *first;
	*first = new;


}
void display(listptr first){
		int sum;
	listptr temp;
	
	for(temp = first; temp!=NULL; temp = temp->link){
		sum=temp->marks1+temp->marks2+temp->marks3;
	temp->total=sum;
	if((sum/3)>90){
		temp->grade='S';
		}
	else if((sum/3)>80){
		temp->grade='A';
		
	}
	else if((sum/3)>70){
		temp->grade='B';
		
	}
	else if((sum/3)>60){
		temp->grade='C';
		
	}
	else if((sum/3)>50){
		temp->grade='D';
		
	}
	else if((sum/3)>40){
		temp->grade='E';
		
	}	
	else {
	temp->grade = 'F';
	}
	
	printf("%s\t%s\t%d\t%d\t%d\t%d\t%c\t%f", temp->usn, temp->name, temp->marks1, temp->marks2, temp->marks3,temp->total,temp->grade,temp->attendance);
		printf("\n");
	}
}

void delete(listptr *first){
	listptr temp;
	temp=*first;
	*first=(*first)->link;
	free(temp);
	
}
listptr search(listptr first){
	while(first){
		if(first->grade=='F' || (first->attendance)<75)
			return first;
	first = first->link;
			
	}
	return NULL;
}

void deleteA(listptr *first){
	listptr q, temp = *first;
	q = search(temp);
	if(q){
		if(q==*first)
			*first = (*first)->link;
		else {
			while(temp->link!=q){
				temp=temp->link;
			}
			temp->link = q->link;
		}
		free(q);
	}
}

/*void bubbleSort(listptr first) 
{ 
    int swapped, i; 
    listptr ptr1; 
    listptr lptr = NULL; 
  
    
    if (first == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = first; 
  
        while (ptr1->link!=lptr) 
        { 
            if (ptr1->total >ptr1->link->total) 
            {  
                swap(ptr1, ptr1->link); 
                swapped = 1; 
            } 
            ptr1 = ptr1->link; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
    
    display(lptr);
} 
  

void swap(listptr a, listptr b) 
{ 
    int temp = a->total; 
    a->total = b->total; 
    b->total = temp; 
} */
void displayt(listptr first){
    
    int max = INT_MIN; 
  	listptr temp;
    
    while (first!= NULL) { 
  
      
        if (max < first->total) {
			temp = first;
            max = first->total; 
		}        first = first->link; 
    } 
    printf("%s\t%s\t has the hisghest", temp->name, temp->usn);

} 	

