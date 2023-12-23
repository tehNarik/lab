namespace DA_LR5;

public class WorkersSendler
{
    public List<int> Send(List<int> probabilities, int workers)
    {
        ItemSelecter itemSelecter = new ItemSelecter();
        Random random = new Random();
        List<int> distribution = new List<int>(Enumerable.Repeat(0, probabilities.Count));
        for (int i = 0; i < workers; i++)
        {
            int rand = random.Next(0, 1000);
            int indexItem = itemSelecter.Select(probabilities, rand);
            distribution[indexItem]++;
        }

        return distribution;
    }
}