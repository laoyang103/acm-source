#include <stdio.h>
#include <string.h>

#define BQ_NODE_DATA_LEN 5

#define MAX(a, b) a > b ? a:b
#define MIN(a, b) a > b ? b:a

typedef struct _bq_node
{
    int index;
    int next;
    int hd_start;
    int hd_end;
    char data[BQ_NODE_DATA_LEN];
    char used[BQ_NODE_DATA_LEN];
} bq_node;



void init_block_queue(bq_node *bq, int size)
{
    int i;

    bq[0].hd_start = 0;         /* The block queue head node point */ 
    bq[0].hd_end = size - 1;    /* The block queue tail node point */ 
    bq[0].next = 1;             /* The block queue first node point, head node has no data */

    for (i = 1;i < size;i++) {
        bq[i].index = i;
        bq[i].next = i + 1;
        bq[i].hd_start = (i-1)*BQ_NODE_DATA_LEN;
        bq[i].hd_end= i*BQ_NODE_DATA_LEN - 1;
    }
    bq[bq[0].hd_end].next = -1;
}

void en_block_queue(bq_node *bq, char *en_data, int pos, int len)
{
    int i, head;
    int data_idx = 0;
    int data_start = pos;
    int data_end = pos + len - 1;

    head = bq[0].hd_start;

    bq_node *curr = &bq[bq[head].next];
    for (;-1 != curr->next;curr = &bq[curr->next]) {
        if (curr->hd_start > data_end || curr->hd_end < data_start) {
            continue;
        }

        for (i = curr->hd_start;i <= curr->hd_end;i++) {
            if (i >= data_start && i <= data_end) {
                data_idx = i - curr->hd_start;
                curr->used[data_idx] = 1;
                curr->data[data_idx] = en_data[i - pos];
            }
        }
    }
}

void print_block_queue(bq_node *bq)
{
    int i, head;
    head = bq[0].hd_start;

    bq_node *curr = &bq[bq[head].next];
    for (;-1 != curr->next;curr = &bq[curr->next]) {
        for (i = 0;i < BQ_NODE_DATA_LEN;i++) {
            if (0 == curr->data[i]) {
                printf(".");
            } else {
                printf("%c", curr->data[i]);
            }
        }
        puts("");
    }
}

int de_block_queue(bq_node *bq, char *buf, int buf_len) 
{
    int i, head;

    head = bq[0].hd_start;
    bq_node *curr = &bq[bq[head].next];

    if(buf_len <= BQ_NODE_DATA_LEN) {
        fprintf(stderr, "BLOCK_QUEUE: buffer len must large than %d.\n", BQ_NODE_DATA_LEN);
        return 0;
    }

    for (i = 0;i < BQ_NODE_DATA_LEN;i++) {
        if (!curr->used[i]) {
            return 0;
        } else {
            buf[i] = curr->data[i];
            curr->used[i] = 0;
        }
    }

    bq_node *head_node = &bq[bq[0].hd_start];
    bq_node *tail_node = &bq[bq[0].hd_end];

    curr->hd_start = tail_node->hd_end + 1;
    curr->hd_end = curr->hd_start + BQ_NODE_DATA_LEN - 1;

    head_node->next = curr->next;
    curr->next = tail_node->next;
    tail_node->next = curr->index;

    bq[0].hd_end = curr->index;

    return BQ_NODE_DATA_LEN;
}

int main()
{
    int i, j;
    char buf[100];
    bq_node global_bq[10];

    memset(global_bq, 0, sizeof(global_bq));
    init_block_queue(global_bq, 10);

    char str0[] = "++++++++++";
    char str1[] = "----------";
    char str2[] = "********************";
    char str3[] = "0000000000";

    puts("================\n");
    en_block_queue(global_bq, str0, 0, strlen(str0));
    print_block_queue(global_bq);
    puts("================\n");

    puts("================\n");
    de_block_queue(global_bq, buf, 100);
    print_block_queue(global_bq);
    puts("================\n");

    puts("================\n");
    en_block_queue(global_bq, str1, 10, strlen(str1));
    print_block_queue(global_bq);
    puts("================\n");

    puts("================\n");
    de_block_queue(global_bq, buf, 100);
    print_block_queue(global_bq);
    puts("================\n");

    puts("================\n");
    en_block_queue(global_bq, str2, 30, strlen(str2));
    print_block_queue(global_bq);
    puts("================\n");

    puts("================\n");
    de_block_queue(global_bq, buf, 100);
    de_block_queue(global_bq, buf, 100);
    print_block_queue(global_bq);
    puts("================\n");

    puts("================\n");
    en_block_queue(global_bq, str3, 50, strlen(str3));
    print_block_queue(global_bq);
    puts("================\n");
    // puts("================");
    // en_block_queue(global_bq, "fghijk", 15, 6);
    // print_block_queue(global_bq);
    // puts("================");
    // en_block_queue(global_bq, "lmnopq", 9, 6);
    // print_block_queue(global_bq);
    // puts("================");

    return 0;
}
