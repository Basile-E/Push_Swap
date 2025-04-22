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
