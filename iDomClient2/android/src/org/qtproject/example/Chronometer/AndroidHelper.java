//
//AndroidHelper.java
//
package org.qtproject.example.Chronometer;

import org.qtproject.qt.android.QtNative;
import org.qtproject.qt.android.bindings.QtService;
import android.app.Notification;
import android.app.NotificationManager;

import android.content.Context;
import android.os.Vibrator;
import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import android.net.Uri;
import android.os.BatteryManager;

import android.content.Intent;
import android.content.IntentFilter;

import android.app.PendingIntent;
import android.graphics.Color;
import android.graphics.BitmapFactory;
import android.app.NotificationChannel;
import android.content.pm.PackageManager;

import android.R;

public class AndroidHelper extends org.qtproject.qt.android.bindings.QtActivity
{

public static Vibrator m_vibrator;

public static NotificationManager m_notificationManager;
public static Notification.Builder m_builder;

public static BatteryManager battery;

public static AndroidHelper m_instance_n;

public static AndroidHelper m_instance;

public AndroidHelper()
{
m_instance_n = this;
}

public static void vibrate(int x)
{
if (m_vibrator == null)
{
if (m_instance_n != null)
{
m_vibrator = (Vibrator) m_instance_n.getSystemService(Context.VIBRATOR_SERVICE);
m_vibrator.vibrate(x);
}

   }
   else m_vibrator.vibrate(x);

}

public static void makeToast(final String s)
    {
        m_instance_n.runOnUiThread(new Runnable() {
                 public void run() {
                     Toast.makeText(m_instance_n.getApplicationContext(),
                                    s,
                                    Toast.LENGTH_SHORT).show();
                 }
              });
    }

public static boolean hasPermission(Context context, String permission) {

    int res = context.checkCallingOrSelfPermission(permission);

    return res == PackageManager.PERMISSION_GRANTED;

}

public static void notify(Context context, String message)
    {
        try {
            m_notificationManager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);

            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
                int importance = NotificationManager.IMPORTANCE_DEFAULT;
                NotificationChannel notificationChannel = new NotificationChannel("Qt", "Qt Notifier", importance);
                m_notificationManager.createNotificationChannel(notificationChannel);
                m_builder = new Notification.Builder(context, notificationChannel.getId());
            } else {
                m_builder = new Notification.Builder(context);
            }

                    //.setSmallIcon(R.drawable.icon)
                    //.setLargeIcon(BitmapFactory.decodeResource(context.getResources(), R.drawable.icon))
           m_builder.setContentTitle("A message from Qt!")
                    .setContentText(message)
                    .setDefaults(Notification.DEFAULT_SOUND)
                    .setColor(Color.GREEN)
                    .setAutoCancel(true);

            m_notificationManager.notify(0, m_builder.build());
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

public static void share(String text) {

Intent sendIntent = new Intent();
sendIntent.setAction(Intent.ACTION_SEND);
sendIntent.putExtra(Intent.EXTRA_TEXT, text);
sendIntent.setType("text/plain");
QtNative.activity().startActivity(sendIntent);


}
//////end class

}
