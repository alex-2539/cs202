class symbol
{
  public:
  symbol();
  symbol(const symbol &srcSymbol);
  ~symbol();

  void setname(char *string);
  char* getname();

  void setbonus(int number);
  int getbonus();

  void setvalidBonus();
  bool getvalidBonus();

  void printsymbol()const;
  void copysymbol(symbol stdsymbol);

  private:
  char *name;
  int bonus;
  bool validBonus;
};

class reel
{
  public:
  reel();
  reel(const reel &srcReel);
  ~reel();

  void setreel(symbol *initial);

  symbol* getsymbols();

  int spinreel();

  void printreel()const;

  private:
  symbol *symbols;
  int payline;
};