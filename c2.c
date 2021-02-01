#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct adjlist {
	int x;
	int y;
}adj;

struct node {
	int value;
	struct adjlist adj_list[4];
	int isvisit;
	int max_value;
}node;

struct node node_info[501][501];

int cal(struct node node[][501], int i, int j);
void get_adjlist(struct node node_info[][501],int n);
void main() {
	int n;
	int altitude;
	int result = 0;

	if (scanf("%d", &n) == 1);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (scanf("%d", &altitude) == 1);
			node_info[i][j].value = altitude;
			for (int k = 0; k < 4; k++) {
				node_info[i][j].adj_list[k].x = 0;
				node_info[i][j].adj_list[k].y = 0;
			}
			node_info[i][j].isvisit = 0;
			node_info[i][j].max_value = 0;
		}
	}
	
	get_adjlist(node_info,n);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			int k = 0;
			result = 0;
			int max_val[4] = {0,0,0,0};
			if (node_info[i][j].isvisit == 1)
				continue;
			else {
				for (k; k < 4; k++) {
					if (node_info[i][j].adj_list[k].x != 0) {
						max_val[k] = cal(node_info, node_info[i][j].adj_list[k].x, node_info[i][j].adj_list[k].y);
					}
					else
						break;
					}
				for (k -= 1; k >= 0; k--) {
					if(result<max_val[k])
					result = max_val[k];
					}
					if(node_info[i][j].max_value< result - node_info[i][j].value)
					node_info[i][j].max_value = result - node_info[i][j].value;
				}}}
		for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (result < node_info[i][j].max_value)
				result = node_info[i][j].max_value;
		}}
	printf("%d", result);
}

void get_adjlist(struct node node_info[][501],int n){

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			int current_alti = node_info[i][j].value;
			int current_max_alti = node_info[i][j].max_value;
			int k = 0;
			if (i > 1) {
				if (current_alti < node_info[i - 1][j].value) {
					node_info[i][j].adj_list[k].x = i - 1;
					node_info[i][j].adj_list[k].y = j;
					k++; 
				}
			}
			if (i < n) {
				if (current_alti < node_info[i + 1][j].value) {
					node_info[i][j].adj_list[k].x = i + 1;
					node_info[i][j].adj_list[k].y = j; 
					k++;
				}
			}
			if (j > 1) {
				if (current_alti < node_info[i][j - 1].value) {
					node_info[i][j].adj_list[k].x = i;
					node_info[i][j].adj_list[k].y = j - 1; 
					k++;
				}
			}
			if (j < n) {
				if (current_alti < node_info[i][j + 1].value) {
					node_info[i][j].adj_list[k].x = i;
					node_info[i][j].adj_list[k].y = j + 1; 
					k++;
				}
			}
		}
	}
}


int cal(struct node node[][501], int i, int j) {
	int max_val[4];
	int result = 0;
	int k = 0;

		if( node[i][j].adj_list[0].x == 0){
		node[i][j].isvisit = 1;
		return node[i][j].value;
		}

	else if (node[i][j].isvisit == 1)
		return node[i][j].max_value + node[i][j].value;

	else {
		for (k; k < 4; k++) {
			if (node[i][j].adj_list[k].x != 0) {
				max_val[k] = cal(node, node[i][j].adj_list[k].x, node[i][j].adj_list[k].y);
			}
			else
				break;
		}

		for (k -= 1; k >= 0; k--) {
			if (max_val[k] > result)
				result = max_val[k];
		}
		node[i][j].max_value = result - node[i][j].value;
		node[i][j].isvisit = 1;

		return result;
	}
}