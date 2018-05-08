#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{
    Node * head;
    SList(){
        this->head = nullptr;
    }

    //destrutor
    ~SList(){
       head = deletarTudo(head);
    }


    void Clear(){

        head = deletarTudo(head);
    }

    Node * deletarTudo(Node * node){
        if(node == nullptr)
            return nullptr;
        deletarTudo(node->next);
        delete node;
        return nullptr;
    }

    Node * arrancaRabo(Node * node, int value){
           if(node == nullptr)
               return nullptr;
           node->next = arrancaRabo(node->next, value);
           if(node->next == nullptr){
               if(node->value != value){
                   delete node;
                   return nullptr;
               }else{
                   return node;
               }
           }
        return node;
        }

    void r_arrancarabo(int value){
        arrancaRabo(head, value);
    }


    Node * _arrancaVenta(Node * node, int value){
         if(node == nullptr)
             return nullptr;
         if(node->value == value)
             return node;

         auto aux = node;
         delete node;
         node = nullptr;
         aux = _arrancaVenta(aux->next, value);
         return aux;
     }

     void arrancaVenta(int value){
         head = _arrancaVenta(head, value);
     }

     void push_front(int value){
         this->head = new Node(value, this->head);
 //        Node * node = new Node(value);
 //        node->next = head;
 //        this->head = node;
     }

    //metodo apaga da frente
    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

//    //metodo adiciona no final
        void push_back(int value){ //todo
            if(head == nullptr){
                head = new Node(value);
                return;
            }
            auto node = head;
            while(node->next != nullptr)
                node = node->next;
            node->next = new Node(value);
    }

//    //metodo adiciona no final recursivo
    Node * _push_back(Node * node, int value){
        if(node->next == nullptr){
            node->next = new Node(value);
            return node->next;
        }
          node = _push_back(node->next, value);
          return node;

    }

    //metodo adiciona no final recursivo
    void rpush_back(int value){
        _push_back(head, value);
    }

//    //metodo apaga do final iterativo
    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

//    //metodo apaga do final recursivo
    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
        return node;
    }

//    //metodo apaga do final recursivo, chama a função recursiva
    void rpop_back(){
        this->head = _rpop_back(head);
    }

//    //metodo mostar iterativo
    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

//    //metodo mostrar recursivo
   void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
   }

        //metodo mostrar recursivo
    void rshow(){
        _rshow(head);
        cout << endl;
    }

//    //metodo remover recursivo
    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
        return node;
    }

//    //metodo remover recursivo
    void rremove(int value){
        head = _remove(head, value);
    }

//    //metodo remover iterativo
//    void iremove(int value){
//        if(head == nullptr)
//            return;
////        if(head->value = value && head->next = nullptr){
////            head = nullptr;
////        }
//        if(head->value == value && head->next != nullptr){
//            head = head->next;
//            delete head;
//        }

//    }

//    //metodo inserir ordenado iterativo
    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

//    //metodo inserir oredenado recursivo
    //    Node * _rinserir_ordenado(Node * node, int value){

    //    }

//    //metodo inserir oredenado recursivo
//    void rinserir_ordenado(int value){
//        _rinserir_ordenado(head, value);
//    }

//    //metodo somar
    int rsomar(Node * node){
        if(node->next == nullptr)
            return node->value;

        return node->value + rsomar(node->next);
    }

//    //metodo somar chamando recursivo
    void somar(){
        rsomar(head);
         cout << rsomar(head) << endl;
    }

    int size(){
        int cont = 0;
        auto node = head;

        while(node != nullptr ){
            cont++;
            node = node->next;

        }
        return cont;
    }

//    //metodo menor recursivo
    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }
public:
    void min(){
        cout << "O menor valor é: " << rmin(head) << endl;
    }
};

int main(){
    SList lista;
    cout << "Elementos da lista:" << endl;
    lista.push_back(4);
    lista.rpush_back(8);
    lista.push_front(2);
    lista.rshow();

   cout << "Método push front:" << endl;
    lista.push_front(1);
    lista.rshow();

    lista.r_arrancarabo(2);
    lista.rshow();

    cout << "Método push back:" << endl;
    lista.rpush_back(7);
    lista.rshow();

    cout << "Método somar :"<< endl;
    lista.somar();
    lista.rshow();

    cout << "Método pop  front: " << endl;
    lista.pop_front();
    lista.rshow();

    cout<< "Método de inserir ordenado(num 6):" << endl;
    lista.inserir_ordenado(6);
    lista.rshow();

    cout << "Método pop  back: " << endl;
    lista.pop_back();
    //lista.rpop_back();
    lista.rshow();

    cout << "Método de remover(removendo núm 4):" << endl;
    lista.rremove(4);
    lista.rshow();

    cout << "Método size:  "  <<  lista.size() << endl;
    lista.rshow();

    cout << "Adicionando mais valores:" << endl;
    lista.push_back(45);
    lista.push_back(41);
    lista.push_back(12);
    lista.push_back(11);
    lista.rshow();

    cout << "Método de arrancar venta:" << endl;
    lista.arrancaVenta(45);
    lista.rshow();

    cout << "Método de arrancar rabo:" << endl;
    lista.r_arrancarabo(41);
    lista.rshow();

    cout << "Método clear:" << endl;
    lista.Clear();
    lista.rshow();
    //lista.rinserir_ordenado(9);


//    lista.min();
////  lista.iremove(1);
//    lista.rshow();
////  lista.ishow();
    return 0;
}
