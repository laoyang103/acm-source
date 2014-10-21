#include <stdio.h>
#include <string.h>

#define BQ_HEAD 0
#define BQ_SIZE 22

typedef struct _bq_node
{
    int index;
    int next;
    int net_index;
    char data;
    char stat;
} bq_node;

bq_node global_bq[BQ_SIZE];

void init_block_queue(bq_node *bq, int size)
{
    int i;

    bq[BQ_HEAD].index = 0;                /* The block queue head node point */ 
    bq[BQ_HEAD].net_index = size - 1;     /* The block queue tail node point */ 
    bq[BQ_HEAD].next = 1;                 /* The block queue first node point, head node has no data */

    for (i = 1;i < size;i++) {
        bq[i].index = i;
        bq[i].net_index = i;
        bq[i].next = i + 1;
        bq[i].stat = bq[i].data = 0;
    }
    bq[bq[BQ_HEAD].net_index].next = -1;  /* The last node */
}

void en_block_queue(bq_node *bq, char *en_data, int pos, int len)
{
    int i = 0;
    int fill_len = 0;
    int fill_pos = pos;

    bq_node *curr = &bq[bq[BQ_HEAD].next];
    for (;-1 != curr->next;curr = &bq[curr->next]) {
        if (fill_len >= len) break;
        if (fill_pos == curr->net_index) {
            curr->stat = 1;
            curr->data = en_data[fill_len];
            fill_pos++;
            fill_len++;
        } else if (curr->net_index < fill_pos) {
            continue;
        } else {
            break;
        }
    }
}

void print_block_queue(bq_node *bq)
{
    int line = 1;
    bq_node *curr = &bq[bq[BQ_HEAD].next];
    for (;-1 != curr->next;curr = &bq[curr->next]) {
        if (0 == curr->data) {
            printf(".");
        } else {
            printf("%c", curr->data);
        }
        if (0 == (line++ % 5)) {
            puts("");
        }
    }
}

int de_block_queue(bq_node *bq, char *buf, int buf_len) 
{
    int copy_len = 0;
    bq_node *head_node = NULL;
    bq_node *tail_node = NULL;
    bq_node *curr = &bq[bq[BQ_HEAD].next];

    for (;-1 != curr->next;curr = &bq[bq[BQ_HEAD].next]) {
        if (0 == curr->stat) break;
        if (copy_len >= buf_len) break;

        buf[copy_len++] = curr->data;
        curr->data = curr->stat = 0;

        head_node = &bq[bq[BQ_HEAD].index];
        tail_node = &bq[bq[BQ_HEAD].net_index];

        curr->net_index = tail_node->net_index + 1;
        head_node->next = curr->next;
        curr->next = tail_node->next;
        tail_node->next = curr->index;

        bq[BQ_HEAD].net_index = curr->index;
    }
    return copy_len;
}

int main()
{
    int cp_len;
    char buf[100];
    memset(global_bq, 0, sizeof(global_bq));
    init_block_queue(global_bq, BQ_SIZE);

    char str0[] = "+++++";
    char str1[] = "----------";
    char str2[] = "****";
    char str3[] = "0000000000";

    puts("================");
    en_block_queue(global_bq, str0, 1, strlen(str0));
    print_block_queue(global_bq);
    puts("================");

    puts("================");
    cp_len = de_block_queue(global_bq, buf, 3);
    buf[cp_len] = 0;puts(buf);
    puts("================");

    puts("================");
    en_block_queue(global_bq, str1, 10, strlen(str1));
    print_block_queue(global_bq);
    puts("================");

    puts("================");
    en_block_queue(global_bq, str3, 16, strlen(str3));
    print_block_queue(global_bq);
    puts("================");

    puts("================");
    cp_len = de_block_queue(global_bq, buf, 100);
    buf[cp_len] = 0;puts(buf);
    puts("================");

    return 0;
}
