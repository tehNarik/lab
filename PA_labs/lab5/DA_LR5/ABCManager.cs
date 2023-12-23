namespace DA_LR5;

public class ABCManager
{
    public List<int> Manage(Hive hive, List<Item> items, int backpackWeight)
    {
        ABC abc = new ABC();
        FinalCalculate finalCalculate = new FinalCalculate();
        NumAreaManager numAreaManager = new NumAreaManager();
        List<int> usedItems = abc.Start(hive, items, backpackWeight);
        int maxCost = finalCalculate.Cost(items, usedItems);
        int numArea = numAreaManager.Manage();
        MassageWriter.Write(Massages.BeeSend);
        for (int i = 0; i < numArea - 1; i++)
        {
            List<int> newUsedItems = abc.Start(hive, items, backpackWeight);
            int cost = finalCalculate.Cost(items, newUsedItems);
            if (cost > maxCost)
            {
                maxCost = cost;
                usedItems = newUsedItems;
            }
        }

        return usedItems;
    }
}