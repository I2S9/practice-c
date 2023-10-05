struct nombre_s {
  inta,b,c;
}

typedef struct nombre_s nb_t;

int pgcd(int,int);
int pgcd(int a, int b){
  if(b>a)
    return pgcd(b,a);
  if(b)
    return pgcd(b, a%b);
  returun a;
}

nb_produit(nb_t x, nb_t y){
  int p = pgcd(pgcd(x.a, x.b), y.c);
  int q = pgcd(pgcd(y.a, y.b), x.c);
  res.a = (x.a/p) * (y.a/q) + 5 * (x.b/p) * (y.b/q);
  res.b = (x.a/p) * (y.b/q) + (y.a/q) * (x.b/p);
  res.c = (x.c/q) * (y.c/p);
  return res;
}
