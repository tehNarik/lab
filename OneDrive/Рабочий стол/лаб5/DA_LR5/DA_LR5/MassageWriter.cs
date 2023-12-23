
using System.Xml;

namespace DA_LR5;

public static class MassageWriter
{
    public static void Write(string text)
    {
        Console.WriteLine(text);
    }

    public static void WriteArg(string text, int arg)
    {
        Console.WriteLine(text + arg);
    } 
    
    public static void WriteArgNoEnter(string text, int arg)
    {
        Console.Write(text + arg + " ");
    } 
}