#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_DATA_SIZE 102

typedef struct{
	char str[MAX_DATA_SIZE];
	int top;
}stack;

void init_stack(stack* s) {
	s->top = -1;
}

int is_empty(stack* s) {
	return s->top == -1;
}
int is_full(stack* s) {
	return s->top == MAX_DATA_SIZE - 1;
}
void push(stack* s, char c) {
	if (is_full(s)) return;
	s->str[++s->top] = c;
}
char peek(stack* s) {
	if (is_empty(s)) return '\0';
	return s->str[s->top];
}
char pop(stack* s) {
	if (is_empty(s)) return '\0';
	return s->str[s->top--];
}

int main() {
	char str_buf[MAX_DATA_SIZE];

	while (1) {
		
		fgets(str_buf, 102, stdin);
		if (strcmp(str_buf, ".\n") == 0) break;
		stack s;
		init_stack(&s);
		for(int i=0;i<strlen(str_buf);i++){
			if (str_buf[i] == '(' || str_buf[i] == '[') {
				push(&s, str_buf[i]);
			}
			else if (str_buf[i] == ')') {
				if (peek(&s) == '(') pop(&s);
				else {
					push(&s, str_buf[i]);
					continue;
				}
			}
			else if (str_buf[i] == ']') {
				if (peek(&s) == '[') pop(&s);
				else {
					push(&s, str_buf[i]);
					continue;
				}
			}
		}
		if (is_empty(&s)) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}
