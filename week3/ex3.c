#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} node;

typedef struct linked_list {
	struct node* root;
	struct node* tail;
} linked_list;

void insert_node(linked_list *list, int value) {
	node* new_node = malloc(sizeof(node));
	new_node->value = value;

	if(list->root == NULL) {
		list->root = new_node;
	}
	if(list->tail != NULL) {
		list->tail->next = new_node;
	}
	list->tail = new_node;
}

void delete_node(linked_list* list, int value) {
	if(list->root == NULL) {
		return;
	}

	if(list->root->value == value) {
		list->root = list->root->next;
		if(list->tail == list->root) {
			list->tail = NULL;
		}
	} else if(list->root->next != NULL) {
		node* current_node = list->root;
		while(current_node->next->value != value) {
			current_node = current_node->next;
			if(current_node->next == NULL) {
				break;
			}
		}

		if(current_node->next != NULL) {
			current_node->next = current_node->next->next;
		}
	}
}

void print_list(linked_list* list) {
	node* current_node = list->root;
	while(current_node != NULL) {
		printf("%d ", current_node->value);
		current_node = current_node->next;
	}
	printf("\n");
}

int main() {
	linked_list* list = malloc(sizeof(linked_list));
	insert_node(list, 1);
	insert_node(list, 94);
	insert_node(list, 2);
	insert_node(list, 99);
	insert_node(list, 93);
	insert_node(list, 94);
	insert_node(list, 92);
	insert_node(list, 11);
	insert_node(list, 43);
	insert_node(list, 66);
	print_list(list);
	delete_node(list, 12345);
	print_list(list);
	delete_node(list, 2);
	print_list(list);
	delete_node(list, 92);
	print_list(list);
	delete_node(list, 43);
	print_list(list);
	delete_node(list, 66);
	print_list(list);
}
