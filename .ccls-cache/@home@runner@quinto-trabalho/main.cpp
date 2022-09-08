#include <iostream>
#include <random>

using namespace std;

std::mt19937 generator(14234);
std::uniform_int_distribution<int> dis(1, 1000);
std::uniform_int_distribution<int> dis_2(1, 26);

struct numero {
  int num;
  numero *right;
  numero *left;
};

struct b_tree {
  numero *root = NULL;
  int size;

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
      int ref=0;
      while (true) {
        cout << atual->num << "anterior esta aqui"<<endl;
        anterior = atual;
  
          atual = atual->left;
          if (atual == NULL) {
            anterior->left = numerovo;
            return;
          }else{
            ref++;
          }
      
          atual = anterior->right;
          if (atual == NULL) {
            anterior->right = numerovo;
            return;          
          }else{
            ref++;
          }
      }
    }
  }

  void popula(int max_vert) {
    // size = max_vert;
    size = 7;
    int kk[7] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++) {
      // int numr = dis(generator);
      // cout << numr << "  ";
      insere(kk[i]);
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
        in_order(atual->left);
        if((atual->left == NULL) && (atual->right == NULL))
          cout << atual->num << " ";
        in_order(atual->right);
      }
    }

  void pos_order(numero *atual) {
    if (atual != NULL) {
      pos_order(atual->left);
      pos_order(atual->right);
      cout << atual->num << " ";
    }
  }

  void pre_order(numero *atual) {
    if (atual != NULL) {
      cout << atual->num << " ";
      pre_order(atual->left);
      pre_order(atual->right);
    }
  }
};

int main() {
  b_tree tree;
  int max = dis_2(generator);
  cout << max << "--" << endl;
  tree.popula(max);
  //tree.printar_de_algum_jeito(tree.root);
  cout << endl;
  cout << endl << "In-order: ";
  tree.in_order(tree.root);
  cout << endl << "Pre-order: ";
  tree.pre_order(tree.root);
  cout << endl << "Post-order: ";
  tree.pos_order(tree.root);
  cout << endl << "Folhas: ";
  tree.show_folhas(tree.root);
}