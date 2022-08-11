#include <stdio.h>

struct tpoint {
    int x, y;
    struct tpoint *next, *prev;
}
typedef struct tpoint point;

struct tsent {
    struct tpoint *first;
    struct tpoint *last;
}
typedef struct tsent sentinela;

void deletePoint(sentinela *s, int x, int y) {
    point *aux, *del;

    aux = s->first;
    while(aux != NULL) {
        if ((aux->x == x) && (aux->y == y)) {
            del = aux;

            if (del == s->first) {
                s->first = s->first->next;
                if (s->first != NULL)
                    s->first->prev = NULL;
                

                if (s->first->prev != NULL)
                    free(s->first->prev);
                s->first->prev = NULL;
            } else
            if (del == s->last) {
                s->last = s->last->prev;
                free(s->last->next);
                s->last->next = NULL;
            } else {
                del = del->prev;
                del->prev->next = del->next;
                del->next->prev = del->prev;
                free(del);
            }
        }
        aux = aux->next;
    }
}

int main() {

}