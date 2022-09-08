#include <iostream>
#include <random>

using namespace std;

std::mt19937 generator(14234);
std::uniform_int_distribution<int> dis(1, 1000);
std::uniform_int_distribution<int> dis_2(10, 26);
std::uniform_int_distribution<int> dis_3(1, 10);
std::uniform_int_distribution<int> dis_4(300, 576);

struct numero {
  int num;
  numero *right;
  numero *left;
};

struct b_tree {
  numero *root = NULL;
  int size;
  int i=0;
  int k=0;
  int t=0;
  bool found = false;

  void insere(int v) {
    numero *numerovo = new numero;
    numerovo->num = v;
    numerovo->right = nullptr;
    numerovo->left = nullptr;
    if (root == NULL) {
      root = numerovo;
    } else {
      numero *atual = root;
      numero *anterior;
      while (true) {
        
        anterior = atual;
  
          atual = atual->left;
          if (atual == NULL) {
            anterior->left = numerovo;
            return;
          }
      
          atual = anterior->right;
          if (atual == NULL) {
            anterior->right = numerovo;
            return;          
          }
      }
    }
  }

  void popula(int max_vert) {
    size = max_vert;
    cout << "Array gerado: ";

    for (int i = 0; i < size; i++) {
      int numr = dis(generator);
      cout << numr << " ";
      insere(numr);
    }
    cout << endl;
  }

  void in_order(numero *atual) {
    if (atual != NULL) {
      in_order(atual->left);
      cout << atual->num << " ";
      in_order(atual->right);
    }
  }

  void show_folhas(numero *atual) {
      if (atual != NULL) {
        if((atual->left == NULL) and (atual->right == NULL)){
          cout << atual->num << " ";
          }
        show_folhas(atual->left);
        show_folhas(atual->right);
      }
    }

  void pos_order(numero *atual) {
    if (atual != NULL) {
      pos_order(atual->left);
      pos_order(atual->right);
      cout << atual->num << " ";
    }
  }
  void print_bonito(numero *atual) {
      if (atual != NULL) {
        k++;
        if(k==2){
          i++;
          k=0;
        }
        for(int w=0;w<i;w++){
          cout<<"\t";
        }
        if((atual->left != NULL) || (atual->right != NULL)){
          cout << "+" <<atual->num << endl;
        }else{
          cout << atual->num << endl;
        }
        
        print_bonito(atual->left);
        print_bonito(atual->right);
      }
    }

  void pre_order(numero *atual) {
    if (atual != NULL) {
      cout << atual->num << " ";
      pre_order(atual->left);
      pre_order(atual->right);
    }
  }
  void achar(numero *atual,int v){
    found = false;
    t=0;
    achar_(atual,v);
    if(t>=size && found == false){
        cout << "valor gerado: "<< v << " Diagnostico: faltante"<<endl;
    }
  }

  void achar_(numero *atual,int v) {
    t++;
    if (atual != NULL) {
      
      if (atual->num == v){
        cout << "valor gerado: "<< v << " Diagnostico: presente"<<endl;
        found = true;
      }
      achar_(atual->left,v);
      achar_(atual->right,v);
    }
  }
};

int main() {
  b_tree tree;
  int max = dis_2(generator);
  tree.popula(max);
  tree.print_bonito(tree.root);
  cout << endl << "In-order: ";
  tree.in_order(tree.root);
  cout << endl << "Pre-order: ";
  tree.pre_order(tree.root);
  cout << endl << "Post-order: ";
  tree.pos_order(tree.root);
  cout << endl << "Folhas: ";
  tree.show_folhas(tree.root);
  cout << endl;
  int para_achar[5] = {1,4,9,8,5};

  for(int i=0;i<dis_3(generator);i++){
    tree.achar(tree.root,dis_4(generator));
  }
}