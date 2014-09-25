#include <stdio.h>
#include <string.h>

#define BQ_NODE_DATA_LEN 5

typedef struct _bq_node
{
    char data[BQ_NODE_DATA_LEN];
    int next;
    int hd_start;
    int hd_end;
} bq_node;



void init_block_queue(bq_node *bq, int size)
{
    int i;
    int head = 0;
    int tail = size - 1;

    bq[head].next = 1;
    for (i = 1;i < size;i++) {
        bq[i].next = i + 1;
        bq[i].hd_start = (i-1)*BQ_NODE_DATA_LEN + 1;
        bq[i].hd_end= i*BQ_NODE_DATA_LEN;
    }
    bq[tail].next = -1;
}

void en_block_queue(bq_node *bq, char *en_data, int pos, int len)
{
    int i, head = 0;
    bq_node *curr = NULL;

    int data_start = pos;
    int data_end = pos + len;

    curr = &bq[bq[head].next];
    for (;-1 != curr->next;curr = &bq[curr->next]) {

        if(curr->hd_start > data_end || curr->hd_end < data_start) {
            continue;
        }

        for (i = curr->hd_start;i <= curr->hd_end;i++) {

            if(i >= data_start && i <= data_end) {
                curr->data[i] = en_data[i];
            }
        }
    }
}

int main()
{
    bq_node global_bq[5];

    memset(global_bq, 0, sizeof(global_bq));
    init_block_queue(global_bq, 5);

    en_block_queue(global_bq, "abcde", 4, 5);
    en_block_queue(global_bq, "fghijk", 9, 6);
    return 0;
}
