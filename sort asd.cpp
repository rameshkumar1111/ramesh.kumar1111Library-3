template<typename T>
int myGreater(Node<T> *A, Node<T> *B)
{
	if(A->row < B->row)
	{
		return -1;
	}
	else if(A->row == B->row)
	{
		if(A->col<B->col)
			return -1;
		else if(A->col>B->col)
			return 1;
		else
			return 0;

	}
	else
	{
		return 1;
	}
}

template<typename T>
void sortList(Node<T> *head) {  
    //Node current will point to head  
    Node<T> *current = head, *index = NULL;  
    int temprow,tempcol,tempval;  
      
    if(head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  
              
            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(myGreater(current,index)==1) {  
                    
                	temprow=current->row;
                	tempcol=current->col;
                	tempval=current->value;

                	current->row=index->row;
                	current->col=index->col;
                	current->value=index->value;

                    index->row=temprow;
                    index->col=tempcol;
                    index->value=tempval; 
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }  
} 
