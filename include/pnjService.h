typedef struct PnjLinkedList PnjLinkedList;
struct PnjLinkedList {
    Item *data;
    PnjLinkedList *next;
};

struct ArrayItemCraft {
    int arrayItemCraft[25][2];
};
typedef struct ArrayItemCraft ArrayItemCraft;

void pnjChoice(Player *, PnjLinkedList *);

void pnjFix(Player *);

void pnjStock(Player *, PnjLinkedList *);

void deleteElementInventory(Item inventory[], int sizeArr, int index);

void insertionToStock(Item *nvItem, PnjLinkedList *actualStockPos);

void displayStock(Player *playerStruct, PnjLinkedList *stock);

void initStructStock(PnjLinkedList *);

void recoverItemStockToInventory(Player *playerStruct, PnjLinkedList *stock);

PnjLinkedList *deleteElementLinkedList(Player *playerStruct, PnjLinkedList *stock, int choiceRecover);

void craftItem(Player *playerStruct);

void initArrayCraftItem(ArrayItemCraft *arrayItemCraft);

extern int countDelet;
extern int choicePnj;