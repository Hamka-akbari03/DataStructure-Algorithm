#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct node
{
    int data;
    node *kiri;
    node *kanan;
};

void tambah(node **root, int databaru)
{
    if (*root == NULL)
    {
        node *baru;
        baru = new node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        cout << "Data bertambah";
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
    else if (databaru == (*root)->data)
        cout << "Data sudah ada";
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << ' ';
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        cout << root->data << ' ';
        inOrder(root->kanan);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << ' ';
    }
}

int main()
{
    int pil, data;
    node *pohon;
    pohon = NULL;
    do
    {
        system("cls");
        cout << "1. Tambah\n";
        cout << "2. PreOrder\n";
        cout << "3. inOrder\n";
        cout << "4. postOrder\n";
        cout << "5. Exit\n";
        cout << "\nPilihan : ";
        cin >> pil;
        switch(pil)
        {
            case 1:
                cout << "\nINPUT : ";
                cout << "\n---------";
                cout << "\nData baru : ";
                cin >> data;
                tambah(&pohon, data);
                break;
            case 2:
                cout << "Preorder";
                cout << "\n-------------------\n";
                if (pohon != NULL)
                {
                    preOrder(pohon);
                }
                else
                    cout << "Masih kosong";
                break;
            case 3:
                cout << "inOrder";
                cout << "\n------------------------\n";
                if (pohon != NULL)
                {
                    inOrder(pohon);
                }
                else  
                    cout << "Masih kosong";
                break;
            case 4:
                cout << "PostOrder";
                cout << "\n------------------------\n";
                if (pohon != NULL)
                {
                    postOrder(pohon);
                }
                else 
                    cout << "Masih kosong";
                break;
            case 5:
                cout << "\nTerima kasih! Program selesai." << endl;
                cout << "Program was made by Muhammad Hamka Akbari (2410817110007)"<< endl;
                cout << endl;

                return 0;
        }
        _getch();
    } while (pil != 5);
    return EXIT_FAILURE;
}