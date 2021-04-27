#include <iostream>
#include <cstdlib>

using namespace std;

int addition()
{
  int row1, row2, col1, col2, i, j;
  cout << "\nВведите количество строк первой матрицы(сложение): ";
  cin >> row1;
  cout << "Введите количество столбцов первой матрицы(сложение): ";
  cin >> col1;
  cout << "Введите количество строк второй матрицы(сложение): ";
  cin >> row2;
  cout << "Введите количество столбцов второй матрицы(сложение): ";
  cin >> col2;
  int Mass[row1][col1], Mass2[row2][col2], MassRes[row1][col2];

  if (row1 != row2 || col1 != col2)
  {
      cout << "\nСложение невозможно\n";
      return 0;
  }
  for (i=0; i<row1; i++)
  {
    for (j=0; j<col1; j++)
    {
      Mass[i][j]=rand() % 25;
      cout << Mass[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "\n";
  for (i=0; i<row2; i++)
  {
    for (j=0; j<col2; j++)
    {
      Mass2[i][j]=rand() % 25;
      cout << Mass2[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "\nРезультат сложения:\n";
  for (i=0; i<row1; i++)
  {
      for(j=0; j<col2; j++)
      {
          MassRes[i][j]=Mass[i][j]+Mass2[i][j];
          cout << MassRes[i][j] << "\t";
      }
      cout << endl;
  }
}

int multiplication()
{
  int row1, row2, col1, col2, i, j;
  cout << "\nВведите количество строк первой матрицы(умножение): ";
  cin >> row1;
  cout << "Введите количество столбцов первой матрицы(умножение): ";
  cin >> col1;
  cout << "Введите количество строк второй матрицы(умножение): ";
  cin >> row2;
  cout << "Введите количество столбцов второй матрицы(умножение): ";
  cin >> col2;

  if (col1 != row2)
  {
    cout << "Умножение невозможно!";
    return 0;
  }

  int Mass[row1][col1], Mass2[row2][col2], MassRes[row1][col2];
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col1; j++)
    {
      Mass[i][j]=rand() %50;
      cout << Mass[i][j] << " ";
    }
    cout << endl;
  }
    cout << "\n";
  for (int i = 0; i < row2; i++)
  {
    for (int j = 0; j < col2; j++)
    {
      Mass2[i][j]=rand() %50;
      cout << Mass2[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col2; j++)
    {
      MassRes[i][j] = 0;
      for (int k = 0; k < col1; k++)
        MassRes[i][j] += Mass[i][k] * Mass2[k][j];
    }
  }

  cout << "Матрица произведения:" << endl;
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < col2; j++)
      cout << MassRes[i][j] << " ";
    cout << endl;
  }

}

int main()
{ int key;
  setlocale(LC_ALL,"");
  cout << "Сложение матриц(1);\nУмножение матриц(2);\nВыход(0);";
  while(key!=0)
  {
  cout << "\nВведите номер: ";
  cin >> key;
  if(key==1)
  {
  addition();
  }
  else if(key==2)
  {
  multiplication();
  }
  else{return 0;}
  }
    return 0;
}
