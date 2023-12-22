namespace DA_LR5;

public class ErrorsWriters
{
    public void Write(Dictionary<string, string> Errors)
    {
        foreach (var error in Errors.Values)
        {
            Console.WriteLine(error);
        }
    }
}