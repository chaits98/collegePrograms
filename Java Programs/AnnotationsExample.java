import java.lang.annotation.*;
import java.lang.reflect.*;

@Retention(RetentionPolicy.RUNTIME)
@interface MyAnnotation
{
    String str();
    int val();
}

@Retention(RetentionPolicy.RUNTIME)
@interface What
{
    String description();
}

@What(description = "What annotation for class")
@MyAnnotation(str = "MyAnnotation string for class", val = 200)
class AnnotationsExample
{
    
    @What(description = "What annotation for class")
    @MyAnnotation(str = "MyAnnotation string for class", val = 200)
    public static void myMethod()
    {
        AnnotationsExample obj = new AnnotationsExample();
        
        try
        {
            Annotation annos[] = obj.getClass().getAnnotations();
            System.out.println("All annotations for Class: ");
            for(Annotation a : annos)
            {
                System.out.println(a);
            }
            
            Method m = obj.getClass().getMethod("myMethod");
            annos = m.getAnnotations();
            System.out.println("All annotations for myMethod: ");
            for(Annotation a : annos)
            {
                System.out.println(a);
            }
        }
        catch(NoSuchMethodException e)
        {
            System.out.println("Method not Found");
        }
    }
    
    public static void main(String[] args)
    {
        myMethod();
    }
}