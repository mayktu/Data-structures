//Exercicio 4.3.5

celula *busca (int x, celula *le){
   celula *p;
   p = le;
   while (p != NULL && p->conteudo != x) 
      p = p->prox; 
   return p;
}

celula *busca_r (int x, celula *le){
   if (le == NULL)  return NULL;
   if (le->conteudo == x)  return le;
   return busca_r (x, le->prox);
}

//NO CABEÇA DE UMA LISTA

   celula *le;
   le = malloc (sizeof (celula));
   le->prox = NULL;
  
  

   
