#include<iostream>

using namespace std;




template <typename T>
struct LinkedList
{
	int row;
	int col;
	T value;
	struct LinkedList<T> *next;
};


template<typename T>
struct LinkedList<T>* getLinkedList(T arr[5][5],int n,int m)
{
	struct LinkedList< T > *tmp,*head=NULL;


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{

			if(arr[i][j]!=0)
			{
				struct LinkedList< T > *node=(struct LinkedList<T>*)malloc(sizeof(struct LinkedList<T>));
				node->row=i;
				node->col=j;
				node->value=arr[i][j];

				if(head==NULL)
				{
					head=node;
					tmp=head;
				}
				else
				{
					tmp->next=node;
					tmp=tmp->next;
				}
			}
		}
	}

	return head;
} 

bool greaterNode(struct LinkedList<T> &A,struct LinkedList<T> &B)
{
	if(A.row<B.row)
	{
		return true;
	}
}


struct LinkedList* transposeList(struct LinkedList *node)
{

	struct LinkedList<T>* tmp=node;

	while(tmp!=NULL)
	{
		int tmpvar=tmp->row;
		tmp->row=tmp->col;
		tmp->col=tmpvar;

		tmp=tmp->next;
	}

	tmp=node;

	while(tmp!=NULL)
	{
		cout<<tmp->row<<" "<<tmp->col<<" "<<tmp->value<<endl;
		tmp=tmp->next;
	}
	

	return node;

}

int main()
{

	int arr[5][5]={{0,0,0,0,1},{2,0,0,3,0},{0,0,0,0,0},{1,2,3,0,0},{0,0,10,0,0}};

	struct LinkedList<int> *tmp,*node= getLinkedList(arr,5,5);
	tmp=node;
	while(tmp!=NULL)
	{	
		cout<<tmp->row<<" "<<tmp->col<<" "<<tmp->value<<endl;
		tmp=tmp->next;
	}

	tmp = transposeList<int>(node);



return 0;
}

