import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import org.json.JSONObject;
import org.json.JSONArray;

public class AgeCounting {

    public static void main(String[] args) {
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://coderbyte.com/api/challenges/json/age-counting"))
                .build();

        client.sendAsync(request, HttpResponse.BodyHandlers.ofString())
                .thenApply(HttpResponse::body)
                .thenApply(AgeCounting::parseAndCountAge)
                .join();
    }

    public static String parseAndCountAge(String responseBody) {
        JSONObject jsonObject = new JSONObject(responseBody);
        String data = jsonObject.getString("data");
        String[] items = data.split(", ");

        int count = 0;
        for (String item : items) {
            if (item.startsWith("age=")) {
                int age = Integer.parseInt(item.substring(4));
                if (age >= 50) {
                    count++;
                }
            }
        }

        System.out.println("Number of items with age 50 and above: " + count);
        return responseBody;
    }
}
