namespace DA_LR5;

public static class Display
{
    public static void Items(List<Item> items)
    {
        
        for (int i = 0; i < items.Count; i++)
        {
            Console.WriteLine("№_" + (i + 1) + " (" + items[i].Weight + "; " + items[i].Cost + ")");
        }
    }

    public static void List(List<int> list)
    {
        for (int i = 0; i < list.Count; i++)
        {
            Console.Write(list[i] + " ");
        }

        Console.WriteLine("");
    }
    
    public static void List(List<double> list)
    {
        for (int i = 0; i < list.Count; i++)
        {
            Console.WriteLine(list[i]);
        }
    }

    public static void Hive(Hive hive)
    {
        Console.WriteLine("Your hive:");
        Console.WriteLine("Scouts: " + hive.scouts);
        Console.WriteLine("Workers: " + hive.workers);
    }

    public static void Result(List<Item> items, List<int> usedItems)
    {
        FinalCalculate finalCalculate = new FinalCalculate();
        Console.WriteLine("Weight = " + finalCalculate.Weight(items, usedItems));
        Console.WriteLine("Cost = " + finalCalculate.Cost(items, usedItems));
    }

    public static void UsedItems(List<Item> items, List<int> usedItems)
    {
        for (int i = 0; i < usedItems.Count; i++)
        {
            if (usedItems[i] != 0)
            {
                Console.WriteLine("№_" + (i + 1) + ": (" + items[i].Weight + "; " + items[i].Cost + ") - " + usedItems[i]);
            }
        }
    }
}