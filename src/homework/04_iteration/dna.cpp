#include "dna.h"

double get_gc_content(const std::string& dna)
{
    double count = 0;
    double percentage;

    for(auto ch: dna)
    {
        if(ch == 'C' || ch == 'G')
        {
            count += 1;
        }
    }

    percentage = count / dna.size();
    return percentage;
}

std::string get_reverse_string(std::string dna)
{
    std::string reversed;

    for(auto ch: dna)
    {
        reversed.insert(0, 1, ch);
    }

    return reversed;
}

std::string get_dna_complement(std::string dna)
{
    std::string reversed_dna = get_reverse_string(dna);
    std::string complement;

    for(auto ch: reversed_dna)
    {
        if(ch == 'T')
        {
            complement.append("A");
        }
        else if(ch == 'A')
        {
            complement.append("T");
        }
        else if(ch == 'C')
        {
            complement.append("G");
        }
        else if(ch == 'G')
        {
            complement.append("C");
        }
    }
    return complement;
}
