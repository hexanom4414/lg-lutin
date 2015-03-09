#ifndef SYMBOLE
#define SYMBOLE


class abstract Symbole
{
    public:
    	int getId();

        Symbole();
        virtual ~Symbole();
    protected:
    	int id;
    private:
};

#endif // SYMBOLE