#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    multimap<int, int> cartas;
    multimap<int, int>::iterator i, j;
    //multimap<int, int> result;
    string result;
    char buffer[50], buffer2[50];
    int n, count, temp, temp2;
    bool v = false, f = false;
    FILE *arq = fopen("input.txt", "r");
    FILE *arqo = fopen("output.txt", "w");
    
    fscanf(arq, "%d", &n);
    temp2 = n*2;
    count = 1;
    
    while(temp2-- > 0)
    {
        fscanf(arq, "%d", &temp);
        cartas.insert(std::pair<int, int>(temp, count++));
    }
    
    i = ++cartas.begin();
    j = cartas.begin();
    count = 0;
    
    do{
        if((i->first == j->first) && !v)
        {
            //result.insert(std::pair<int, int>(j->second, i->second));
            sprintf(buffer, "%d ", j->second);
            sprintf(buffer2, "%d\n", i->second);
            result += buffer;
            result += buffer2;
            f = true;
            v = true;
            count++;
        }
        else
        {
            v = false;
        }
        i++;
        j++;
    }
    while(i != cartas.end());
    
    //if(result.size() == (unsigned)n)
    if(f && count == n)
    {
        // for(multimap<int, int>::iterator k = result.begin(); k != result.end(); k++)
        //    fprintf(arqo, "%d %d\n", k->second, k->first);
        fprintf(arqo, "%s", result.c_str());
    }
    else
    {
        fprintf(arqo, "%d\n", -1);
    }
    
    fclose(arq);
    fclose(arqo);
    return 0;
}
