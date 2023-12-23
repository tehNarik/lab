namespace DA_LR5;

public class ItemsAnalisis
{
    public List<int> CalcProbability(List<Item> items, List<int> randomItems)
    {
        List<int> probabilities = new List<int>();
        SumNectarCalculator sumNectarCalculator = new SumNectarCalculator();
        double sumNectar = sumNectarCalculator.Culc(items, randomItems);
        for (int i = 0; i < randomItems.Count; i++)
        {
            probabilities.Add((int)Math.Round(items[randomItems[i]].Nectar() / sumNectar * 1000));
        }

        return probabilities;
    }
}