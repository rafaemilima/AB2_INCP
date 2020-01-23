#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 256

struct heap 
{
    int size;
    int data[MAX_HEAP_SIZE];
};

typedef struct heap heap;

heap* create_heap()
{
    int i;
    heap *new_heap = (heap*) malloc(sizeof (heap));
    new_heap->size = 0;
    for (i = 0; i <= MAX_HEAP_SIZE; ++i) {
        new_heap->data[i] = 0;
    }
    return new_heap;
}

int is_empty(heap *heap)
{
    return heap->size == 0;
}

int get_parent_index(int i)
{
    return (i-1)/2;
}

int get_left_index( int i)
{
    return (2*i) +1;
}

int get_right_index(int i)
{
    return (2*i) + 2;
}

int has_left_c (heap *heap, int i)
{
    return get_left_index(i) < heap->size;
}

int has_right_c (heap *heap, int i)
{
    return get_right_index(i) < heap->size;
}

int has_paren (int i)
{
    return get_parent_index(i) >= 0;
}

int item_of(heap *heap, int i)
{
    return heap->data[i];
}

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

/*void min_heapify(heap *heap, int i)
{
    int smallest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);
    if (i > 0)
    {
        if(right_index < heap->data[i])
        {
            swap(&heap->data[right_index], &heap->data[i]);
        }
        if(left_index < heap->data[i])
        {
            swap(&heap->data[left_index], &heap->data[i]);
        }
        min_heapify(heap, i -1);
    }
}*/

void min_heapify(heap *heap, int i)
{
    int smallest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);
    if (left_index < heap->size && heap->data[left_index] < heap->data[i]) 
    {
        smallest = left_index;
    } 
    else 
    {
        smallest = i;
    }
    if (right_index < heap->size && heap->data[right_index] < heap->data[smallest]) 
    {
        smallest = right_index;
    }
    if (heap->data[i] != heap->data[smallest]) 
    {
        swap(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}


int dequeue(heap *heap)
{
    if (is_empty(heap)) 
    {
        printf("Heap underflow");
        return -1;
    } 
    
    else 
    {
        int item = heap->data[1];
        heap->data[1] = heap->data[heap->size];
        heap->size--;
        min_heapify(heap, 1);
        return item;
    }
}

void enqueue(heap *heap, int item)
{
    if (heap->size >= MAX_HEAP_SIZE) 
    {
        printf("Heap overflow");
    } 
    else 
    {
        heap->data[++heap->size] = item;
        int key_index = heap->size;
        int parent_index = get_parent_index(heap->size);

        while (parent_index >= 1 && heap->data[key_index] < heap->data[parent_index]) 
        {
            swap(&heap->data[key_index], &heap->data[parent_index]);
            key_index = parent_index;
            parent_index = get_parent_index(key_index);
            //min_heapify(heap, (heap->size)/2);
        }
    }
}


int main()
{
    heap* attempt_h = create_heap();
    enqueue(attempt_h, 4);
    enqueue(attempt_h, 1);
    enqueue(attempt_h, 3);
    enqueue(attempt_h, 6);
    enqueue(attempt_h, 2);
    enqueue(attempt_h, 5);
    min_heapify(attempt_h, 1);
    //min_heapify(attempt_h, (attempt_h->size)/2);
    dequeue(attempt_h);
    dequeue(attempt_h);
    
    for (int i = 0; i <= attempt_h->size; i++)
    {
        printf("%d ", attempt_h->data[i]);
    }
    

    return 0;
}