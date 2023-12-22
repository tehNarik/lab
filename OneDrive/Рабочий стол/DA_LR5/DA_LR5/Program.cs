namespace DA_LR5;

class Program
{
    private static void Main(string[] args)
    {
        const int backpackWeight = 500;
        const int numItems = 100;
        const int maxWeight = 20;
        const int maxCost = 30;
        const int workers = 50;
        const int scouts = 50;

        ItemsManager itemsManager = new ItemsManager();
        ItemsDisplayManager itemsDisplayManager = new ItemsDisplayManager();
        HiveManager hiveManager = new HiveManager();
        EndProgram endProgram = new EndProgram();
        UsedItemsDisplayManager usedItemsDisplayManager = new UsedItemsDisplayManager();
        ABCManager abcManager = new ABCManager();
        
        MassageWriter.Write(Massages.Greeting);

        List<Item> items = new List<Item>();
        Hive hive = new Hive(workers, scouts);
        bool work = true;
        while (work)
        {
            items = itemsManager.Items(items, numItems, maxWeight, maxCost);
            itemsDisplayManager.Manage(items);
            hiveManager.Manage(ref hive);
            List<int> usedItems = abcManager.Manage(hive, items, backpackWeight);
            MassageWriter.WriteArg(Massages.Backpack, backpackWeight);
            Display.Result(items, usedItems);
            usedItemsDisplayManager.Manage(items, usedItems);
            
            if (endProgram.End())
            {
                work = false;
                MassageWriter.Write(Massages.Bye);
            }
            GC.Collect();
        }
    }
}