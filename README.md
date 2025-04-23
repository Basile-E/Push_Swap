# Push_Swap #

fonction LST de la libft

lst_size = prend une lst en param (la head ?)

lst_new = crée un nouveau noeud et renvoi un pointeur vers le noeud 

ex :

int main()
{
    int value = 42;

    // Création d'un nœud avec la valeur 42
    t_list *node = ft_lstnew(&value);

    // Affichage du contenu du nœud
    if (node)
    {
        printf("Content: %d\n", *(int *)(node->content));
        free(node); // Libération de la mémoire
    }
    else
    {
        printf("Allocation failed\n");
    }

    return 0;
}

lst_map = execute une fonction sur la liste passé en param

lst_last = renvoie un pointer vers le dernier noeud de la liste 

lst_iter = applique une fonction de maniere itérative a chaque noeud de la liste 

lst_del_one = supprime un seul noeud de la liste

lst_clear = supprime toute la liste 

lst_add_front = ajoute un noeud au debut de la liste 

lst_add_back = ajoute un noeuf a la fin de la liste




sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no        elements.
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.

{
    void * temp;

    temp == t_list a->value  // enregistre la valeur du premier element de la liste a  
    lst_add_front(b->value , a) // ajoute le premier noeud de la liste b dans la liste a
    lst_add_front(temp, b) // ajoute le temp (valeur du premier noeud de la liste a) au debut de la liste b
}


pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

void *pa()
{
    lst_add_front(b->value, a)
    lst_del_one(b->value)
}

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.

{
    au debut prendre le premier element et le mettre a la fin de la liste puis next-next + 1 ?
}

rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.






a comprendre :

je ne suis pas sur de comprendre comment "initialiser" une liste chainer, quel sont les variables utiliser et comment leurs atribuer des valeurs ? mes args commence en tant que char puis passent en int

est-ce que je suis obliger d'utiliser les type cast ou je suis juste con

je pense etre correct, du coup je track seulement les head des liste et les pointeur next font le liens entre tout les élements de la liste du coup j'aurais head_a et head_b et dans mon main je fait les verrifications, puis j'appel des fonctions qui transforme les arg en int pour les liste puis je crée la liste a et et ensuite en fonction de la taille de la liste a je fait un mini_sort ou j'appel push_swap qui fera les apppels au fonction d'algorithmes 

game plan :

[ ] comprehension des listes et implementation 

[ ] transformation des arg en int utilisable 

[ ] initialisation de la liste a avec les arg 

[ ] création d'un mini_sort en cas de 3 arg (potentiellement pour 5?)

[ ] verrification de si lst_a < 3 fait un appel a mini_sort et fin du programme 

[ ] mise en place de la fonction push_swap et préparation pour l'appel des algo 

[ ] implémentation des algo

[ ] aller boire une bierre 


to-do :

dans la comprehension des liste, est-ce que je peux remplacer la valeur de retour des fonctions lst par un      void * en soit ça devrait pouvoir contenir un pointeur vers head et renvoyer une head ? 

si j'ai besoin d'une ligne dans le main je peux rempalcer le i qui parcour les arg et rempalcer par ac et decrementer 

Fonctions :

je vais avoir besoins d'une ribanbelle de fonctions de liste, un lst_find_element, une fonction make_lst qui prend un head en pointeur et renvoi la head avec la liste 


me faire un github de la libft avec une makefile contenant une commande qui push tout sur git proprement et qui ajoute le libft.h dans le include file et le libft.a dans le lib file, voir ou vont les fichier des fonctions ? et voir si je peux "mettre a jour" la bibliotheque standard <libft.h> juste en changeant les fichiers et en faisant cp libft.h /etc/etc/include/ 

si j'y arrive j'ai une libft hyper facile a utiliser et je peux y ajouter des fonctions tres facilement

