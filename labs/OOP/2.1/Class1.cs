using System;

class MyString
{
    protected string value;

    public MyString(string val)
    {
        value = val;
    }

    public int GetLength()
    {
        return value.Length;
    }

    public virtual void Display()
    {
        Console.WriteLine("Рядок: " + value);
    }
}

class CharString : MyString
{
    public CharString(string val) : base(val) {}

    public string SortDescending()
    {
        char[] chars = value.ToCharArray();
        Array.Sort(chars);
        Array.Reverse(chars);
        return new string(chars);
    }

    public override void Display()
    {
        Console.WriteLine("Символьний рядок: " + value);
        Console.WriteLine("Сортований за спаданням: " + SortDescending());
        Console.WriteLine("Довжина: " + GetLength());
    }

    public string GetValue()
    {
        return value;
    }
}

class Program
{
    static void Main()
    {
        CharString myStr = new CharString("Helllooooooo");
        myStr.Display();
    }
}
