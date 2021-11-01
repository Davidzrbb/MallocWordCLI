typedef struct PnjLinkedList PnjLinkedList;
struct PnjLinkedList {
    Item *data;
    PnjLinkedList *next;
};

void pnjChoice(Player *, PnjLinkedList *);

void pnjFix(Player *);

void pnjStock(Player *, PnjLinkedList *);

void deleteElementInventory(Item inventory[], int sizeArr, int index);

void insertionToStock(Item *nvItem, PnjLinkedList *actualStockPos);

void displayStock(Player *playerStruct, PnjLinkedList *stock);

void initStructStock(PnjLinkedList *);

void recoverItemStockToInventory(Player *playerStruct, PnjLinkedList *stock);

PnjLinkedList *deleteElementLinkedList(Player *playerStruct, PnjLinkedList *stock, int choiceRecover);

void freeLinked(PnjLinkedList *);