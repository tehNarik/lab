namespace DA_LR5;

public class ABC
{
    public List<int> Start(Hive hive, List<Item> items, int backpackWeight)
    {
        ScoutsSendler scoutsSendler = new ScoutsSendler();
        WorkersSendler workersSendler = new WorkersSendler();
        ItemsAnalisis itemsAnalisis = new ItemsAnalisis();
        MaxItemFinder maxItemFinder = new MaxItemFinder();
        MinWeightFinder minWeightFinder = new MinWeightFinder();
        int minWeight = minWeightFinder.Find(items);
        List<int> usedItems = new List<int>(Enumerable.Repeat(0, items.Count));
        int totalWeight = 0;

        while (backpackWeight - totalWeight > minWeight)
        {
            List<int> randomItems = scoutsSendler.Send(hive.scouts, items);
            List<int> probabilities = itemsAnalisis.CalcProbability(items, randomItems);
            List<int> distribution = workersSendler.Send(probabilities, hive.workers);
            int chooseItemIndex = randomItems[maxItemFinder.Find(distribution)];

            if (totalWeight + items[chooseItemIndex].Weight <= backpackWeight)
            {
                totalWeight += items[chooseItemIndex].Weight;
                usedItems[chooseItemIndex]++;
            }
        }
        return usedItems;
    }
}