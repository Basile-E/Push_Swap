#!/bin/bash

# Vérifier si push_swap est exécutable
if [ ! -x ./push_swap ]; then
    echo "Erreur : ./push_swap n'est pas exécutable ou n'existe pas."
    exit 1
fi

# Générer les permutations de 1 à 5 et exécuter ./push_swap pour chacune
permute() {
    local prefix="$1"
    local rest="$2"
    if [ -z "$rest" ]; then
        ./push_swap $prefix | wc -l
    else
        for i in $rest; do
            local new_prefix="$prefix $i"
            local new_rest=""
            for j in $rest; do
                [ "$j" != "$i" ] && new_rest="$new_rest $j"
            done
            permute "$new_prefix" "$new_rest"
        done
    fi
}

# Lancer la permutation initiale avec les nombres de 1 à 5
permute "" "1 2 3"
