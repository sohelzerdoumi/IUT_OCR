#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

enum HISTOGRAMME_TYPE{
    HISTOGRAMME_HORIZONTAL,
    HISTOGRAMME_VERTICAL,

};


class Histogramme
{
    public:
        /** Default constructor */
        Histogramme();
        /** Default destructor */
        virtual ~Histogramme();
    private:
        int * data;
};

#endif // HISTOGRAMME_H
