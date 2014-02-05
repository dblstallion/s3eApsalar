/*
java implementation of the s3eApsalar extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.apsalar.sdk.Apsalar;
import org.json.JSONObject;
import org.json.JSONException;
import android.util.Log;

class s3eApsalar
{
	private static final String TAG = "APSALAR";

    public void s3eApStart(String apiKey, String apiSecret)
    {
		Log.v(TAG, "Session Start");
        Apsalar.startSession(LoaderActivity.m_Activity, apiKey, apiSecret);
    }
    public void s3eApRestart(String apiKey, String apiSecret)
    {
		Log.v(TAG, "Session ReStart");
        Apsalar.restartSession(LoaderActivity.m_Activity, apiKey, apiSecret);
    }
    public boolean s3eApStarted()
    {
        return !"None".equals(Apsalar.getSessionId());
    }
    public void s3eApEnd()
    {
    }
    public void s3eApLogEvent(String name)
    {
        Apsalar.event(name);
    }
    public JSONObject s3eApDictCreate()
    {
        return new JSONObject();
    }
    public void s3eApDictAddString(JSONObject dict, String key, String value)
    {
		try {
			dict.put(key, value);
		} catch(JSONException e) {
			Log.v(TAG, "JSONException in s3eApDictAddString");
		}
    }
    public void s3eApDictAddInt(JSONObject dict, String key, int value)
    {
        try {
			dict.put(key, value);
		} catch(JSONException e) {
			Log.v(TAG, "JSONException in s3eApDictAddInt");
		}
    }
    public void s3eApDictAddFloat(JSONObject dict, String key, float value)
    {
        try {
			dict.put(key, value);
		} catch(JSONException e) {
			Log.v(TAG, "JSONException in s3eApDictAddFloat");
		}
    }
    public void s3eApDictAddDict(JSONObject dict, String key, JSONObject value)
    {
        try {
			dict.put(key, value);
		} catch(JSONException e) {
			Log.v(TAG, "JSONException in s3eApDictAddDict");
		}
    }
    public void s3eApLogEventWithArgs(String name, JSONObject dict)
    {
        Apsalar.eventJSON(name, dict);
    }
	public void s3eApSetFBAppId(String appId)
    {
        Apsalar.setFBAppId(appId);
    }
}
