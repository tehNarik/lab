namespace DA_LR5;

public class InputAreaValidationContext
{
    public static Dictionary<string, string> Validate(string input, int size)
    {
        NumberEntriesValidator numberEntriesValidator = new NumberEntriesValidator();
        IsNumberValidator isNumberValidator = new IsNumberValidator();
        numberEntriesValidator.SetSuccessor(isNumberValidator);
        CorrectNumberAreaValidator correctNumberValidator = new CorrectNumberAreaValidator();
        isNumberValidator.SetSuccessor(correctNumberValidator);

        return numberEntriesValidator.HandleValidation(input, size); 
    }
}