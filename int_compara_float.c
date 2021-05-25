int compara_float(void *x,void *y){
float *a = x,*b = y;
if(*a > *b) return 1;
if (*a < *b) return -1;
if (*a == *b) return 0;
}

int main(){
FilaP f1;

inicializa_fila(&f1,30,sizeof(float));

float x = 7;

inserir(&f1,&x,compara_float);

remover(&f1,&x);
}
