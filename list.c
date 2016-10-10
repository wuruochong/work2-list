/*
Ruochong Wu
Systems Level Programming
Work2 - enlist your coding skills
10/9/2016
*/
#include <stdlib.h>
#include <stdio.h>

struct node {int c; struct node *next;};

void print_list(struct node* a){
  printf("%d-->",a->c);
  if (!(a->next)){
    printf("\n");
    return;
  }
  print_list(a->next);
}

struct node *insert_front(struct node *a, int v){
  struct node* n;
  n = (struct node*)malloc(sizeof(struct node));
  n->c = v;
  n->next = a;
  return n;
}

/*void free_list(struct node *a){
  print_list(a);
  struct node *b = a;
  while(a){
    if (!(a->next)){
      free(a);
      a = 0;
      printf("freed\n");
    }
    else{
      if(!((a->next)->next)){
        free_list(a->next);
        a->next = 0;
      }
      else{
        free_list(a->next);
      }
    }
    a = b;
  }
  return;
}
*/

/*struct node *free_list(struct node *a){
  while(a!=NULL){
    free_help(a);
    printf("%p\n",a);
  }
  printf("ayy");
  return a;
}
*/

void free_node(struct node *a){
  if (!(a->next)){
    free(a);
  }
  else{
    free_node(a->next);
    free(a);
  }
  return;
}

struct node *free_list(struct node *a){
  struct node *r = a;
  free_node(a);
  return r;
}

int main(){
  struct node* a;
  a = (struct node*)malloc(sizeof(struct node));
  struct node* b;
  b = (struct node*)malloc(sizeof(struct node));
  a->c = 1;
  b->c = 2;
  a->next = b;
  b->next = 0;
  print_list(a);
  struct node* n;
  n = insert_front(a, 0);
  print_list(n);
  printf("\n");
  printf("freeing\n");
  printf("%p",free_list(n));
  return 0;
}
