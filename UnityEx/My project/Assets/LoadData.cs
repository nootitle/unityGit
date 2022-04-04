using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LoadData : MonoBehaviour
{
    void Start()
    {
        //object[] Objects = Resources.LoadAll<Sprite>("Sprites");
    }

    public static object[] GetLoadData(string _FileName)
    {
        object[] Objects = Resources.LoadAll<Sprite>(_FileName);

        if (Objects == null)
            return null;

        return Objects;
    }
}

/*
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;
using UnityEditor;

public class SkillSlotController : MonoBehaviour
{
    [SerializeField] private Image SlotSprite;
    [SerializeField] private GameObject SlotEffect;

    private float CoolTime;

    private bool SkillOn;

    private void Start()
    {
        CoolTime = 4.0f;

        SkillOn = false;
    }

    public void StartCooldown()
    {
        if (SkillOn)
            return;

        SkillOn = true;
        StartCoroutine( SkillCooldown() );
    }
    
    IEnumerator SkillCooldown()
    {
        while (SlotSprite.fillAmount < 1.0f)
        {
            SlotSprite.fillAmount += (Time.deltaTime / CoolTime);

            yield return null;
        }
        
        SkillOn = false;
        SlotSprite.fillAmount = 0.0f;

        SlotEffect.SetActive(true);
    }
}


public class SkillSlotEditor : EditorWindow
{
    [MenuItem("Editor Tools/Skill Editor")]
    private static void WindowBox()
    {
        /*
        SkillSlotEditor Window = (SkillSlotEditor)GetWindow(typeof(SkillSlotEditor));
        Window.Show();
        */
/*
GetWindow(typeof(SkillSlotEditor)).Show();
    }



    private Object _Object = null;




private void OnGUI()
{
    object[] Objects = Resources.LoadAll<Sprite>("Sprites");





    EditorGUILayout.BeginHorizontal();

    /***********************************************************
     * [GUILayout]

     * GUILayout.Width(��)
     * GUILayout.Height(��)
     * GUILayout.MinWidth(�� �ּҰ�)
     * GUILayout.MaxWidth(�� �ִ밪)
     * GUILayout.MinHeight(���� �ּҰ�)
     * GUILayout.MaxHeight(���� �ִ밪)
     * GUILayout.ExpandWidth(true or false : ���� Ȯ���� ����ϰų� ���´�)
     * GUILayout.ExpandHeight(true or false : ���� Ȯ���� ����ϰų� ���´�)

     **********************************************************/










    /*****************************************************************************************************************
     * [EditorStyles]  �۲�
     * 
     * ����
     * https://docs.unity3d.com/kr/530/ScriptReference/EditorStyles.html
     * 
     * boldFont   ���� �۲�(Bold)
     * boldLabel   ���� �۲� ��Ÿ��
     * centeredGreyMiniLabel   ���� �۲��� �� ��Ÿ��
     * colorField   ���� �ʵ忡�� ���Ǵ� ��Ÿ��
     * foldout   EditorGUI.Foldout���� ���Ǵ� ��Ÿ��
     * foldoutPreDrop   EditorGUI.Foldout���� ���Ǵ� ��Ÿ��
     * helpBox   EditorGUI.HelpBox�� ���Ǵ� ��Ÿ��
     * inspectorDefaultMargins   �����ڿ��� ���Ǵ� �⺻ ������ ��� ���� �������� �� ��Ÿ�Ϸ� ���� �׷쿡�� ���մϴ�.
     * inspectorFullWidthMargins   �����ڿ��� ���Ǵ� ���� ������ ��� ���� �������� �� ��Ÿ�Ϸ� ���� �׷쿡�� ���մϴ�.
     * label   ���� �ٴ� ��� EditorGUI���� ���Ǵ� ��Ÿ��
     * largeLabel   ū �۲��� �� ��Ÿ��
     * layerMaskField   ���̾� ����ũ���� ���Ǵ� ��Ÿ��
     * miniBoldFont   �۰� ���� �۲�
     * miniBoldLabel   ���� �۾��� ���� �󺧿� ���Ǵ� ��Ÿ��
     * miniButton   ���� ��ư�� ��Ÿ��
     * miniButtonLeft   �۰� �������� ��ư ��Ÿ��
     * miniButtonMid   �۰� �߾ӿ� ����� ��ư ��Ÿ��
     * miniButtonRight   �۰� �������� ��ư ��Ÿ��
     * miniFont   ���� �۲�
     * miniLabel   ���� �۲��� �� ��Ÿ��
     * miniTextField   ���� �ؽ�Ʈ �ʵ忡�� ���Ǵ� ��Ÿ��
     * numberField   ���ڸ� �Է��ϴ� �ʵ忡�� ���Ǵ� ��Ÿ��
     * objectField   ������Ʈ �ʵ忡�� ���Ǵ� ��Ÿ��
     * objectFieldMiniThumb   Style used for object fields that have a thumbnail (e.g Textures).
     * objectFieldThumb   ������Ʈ �ʵ忡�� ���Ǵ� ������ �̹����� ��Ÿ��
     * popup   EditorGUI.Popup�� EditorGUI.EnumPopup���� ���Ǵ� ��Ÿ��
     * radioButton   ���� ��ư�� ���Ǵ� ��Ÿ��
     * standardFont   �Ϲ����� ǥ�� �۲�
     * textArea   EditorGUI.TextArea�� ���Ǵ� ��Ÿ��
     * textField   EditorGUI.TextField���� ���Ǵ� ��Ÿ��
     * toggle   EditorGUI.Toggle���� ���Ǵ� ��Ÿ��
     * toggleGroup   EditorGUILayout.BeginToggleGroup���� ���Ǵ� ��Ÿ��
     * toolbar   â ��ܿ� ǥ���� ���� ������ ��� ��Ÿ��
     * toolbarButton   ���� ���� ���߿��� ���Ǵ� ��Ÿ��
     * toolbarDropDown   ���� ������ ��� �ٿ�� ���Ǵ� ��Ÿ��
     * toolbarPopup   ���� ������ �˾����� ���Ǵ� ��Ÿ��
     * toolbarTextField   ���� ������ �ؽ�Ʈ �ʵ忡 ���Ǵ� ��Ÿ��
     * whiteBoldLabel   ��� �����̰� ���� �� ��Ÿ��
     * whiteLabel   ��� ���� �� ��Ÿ��
     * whiteLargeLabel   ��� ������ ū �۲� �� ��Ÿ��
     * whiteMiniLabel   ��� ���� ���� �۲��� �� ��Ÿ��
     * wordWrappedLabel   ���� �̻��� ���ڰ� �ԷµǾ��� ��, ��ȯ�ϴ� ��Ÿ��
     * wordWrappedMiniLabel   ���� �۲÷� ���� �̻��� ���ڰ� �ԷµǾ��� ��, ��ȯ�ϴ� ��Ÿ��
     ******************************************************************************************************************/
/*
    EditorGUILayout.BeginVertical();
    GUILayout.Space(20);
    GUILayout.Label("Create Skill", EditorStyles.boldLabel);

    EditorGUILayout.BeginHorizontal();
    GUILayout.Space(20);


    _Object = EditorGUILayout.ObjectField("Object Prefab", _Object, typeof(Sprite), false);

    EditorGUILayout.EndHorizontal();




    // ** ���� ����ִ� ���� ����.
    Color Oldcolor = GUI.backgroundColor;

    // ** ���� ���� ���������� ����.
    GUI.backgroundColor = Color.red;


    if (GUILayout.Button("1",
        GUILayout.MinHeight(20), GUILayout.MinWidth(50),
        GUILayout.Height(23), GUILayout.Width(150),
        GUILayout.MaxHeight(25), GUILayout.MaxWidth(300)))
    {
        /*
        GameObject SkillObj = (GameObject)Instantiate(_Object);

        SkillObj.transform.SetParent( GameObject.Find("Canvas").transform );

        Image Tex = SkillObj.GetComponent<Image>();

        Tex.sprite = (Sprite)Objects[0];
         */

/*
        GameObject SkillObj = new GameObject("Temp");

        SkillObj.transform.SetParent(GameObject.Find("Canvas").transform);

        Image Tex = SkillObj.AddComponent<Image>();

        Tex.sprite = (Sprite)_Object;
    }

    // ** ���� ������ ����.
    GUI.backgroundColor = Oldcolor;







    if (GUILayout.Button("2"))
    {

    }

    if (GUILayout.Button("3"))
    {

    }
    EditorGUILayout.EndVertical();

    EditorGUILayout.EndHorizontal();
}
}


/*
public class SkillSlotInspector : Editor
{
    private void OnSceneGUI()
    {
        if (GUILayout.Button("1"))
        {

        }

        if (GUILayout.Button("2"))
        {

        }

        if (GUILayout.Button("3"))
        {

        }
    }
}
 */
