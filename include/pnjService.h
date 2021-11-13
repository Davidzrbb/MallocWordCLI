typedef struct PnjLinkedList PnjLinkedList;
struct PnjLinkedList {
    Item *data;
    PnjLinkedList *next;
};

struct ArrayItemCraft {
    int type;
    int idCreation;
    int arrayItemCraftNecessary[2];
    int arrayQuantityCraftNecessary[2];
    char *name;
    int damage;
    float max_durability;
    float actual_durabiulity;
    int pvRestore;
    int protection;
    int quantity;
};
typedef struct ArrayItemCraft ArrayItemCraft;

struct AllItemCraft {
    ArrayItemCraft itemCraft[25];
};
typedef struct AllItemCraft AllItemCraft;

void pnjChoice(Player *, PnjLinkedList *);

void pnjFix(Player *);

void pnjStock(Player *, PnjLinkedList *);

void deleteElementInventory(Item inventory[], int sizeArr, int index);

void insertionToStock(Item *, PnjLinkedList *);

void displayStock(Player *, PnjLinkedList *);

void initStructStock(PnjLinkedList *);

void recoverItemStockToInventory(Player *, PnjLinkedList *);

PnjLinkedList *deleteElementLinkedList(Player *, PnjLinkedList *, int);

void craftItem(Player *);

void initArrayCraftItem(AllItemCraft *);

int* verifItemCraft(AllItemCraft *, Player *);

void createItemCraft(AllItemCraft *, Player *, int);

void displayItemCraft(AllItemCraft *);

void addItemCraft(AllItemCraft *, Player *, const int*);

void displayItemCraftSection(AllItemCraft *, int);

extern int countDelet;
extern int choicePnj;
extern int sizeInv;