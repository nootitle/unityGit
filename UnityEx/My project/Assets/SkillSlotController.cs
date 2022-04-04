using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEditor;

public class SkillSlotController : MonoBehaviour
{
    [SerializeField] private Image SlotSprite;
    [SerializeField] private GameObject SlotFx;
    [SerializeField] private float CoolTime = 4.0f;
    private bool SkillOn;
    Coroutine co = null;

    void Start()
    {
        SkillOn = false;
        if (CoolTime <= 0)
            CoolTime = 1.0f;
    }

    void Update()
    {

    }

    public void StartCooldown()
    {
        if (SkillOn) return;
        if (co != null) StopCoroutine(co);
        co = StartCoroutine(SkillCooldown());
        SkillOn = true;
    }

    private void StopCooldown()
    {
        
    }

    IEnumerator SkillCooldown()
    {
        while (SlotSprite.fillAmount < 1.0f)
        {
            SlotSprite.fillAmount += Time.deltaTime * (1 / CoolTime);
            yield return null;
        }

        if (SlotFx != null)
            SlotFx.SetActive(true);
        SlotSprite.fillAmount = 0.0f;

        StartCoroutine(CooldownFx());

        SkillOn = false;
    }

    IEnumerator CooldownFx()
    {
        yield return new WaitForSeconds(1.0f);

        if (SlotFx != null)
            SlotFx.SetActive(false);
    }

    //Animation Event�� ����ؼ� ����� ���� ����(����)
}

public class SkillSlotEditor : EditorWindow
{
    [MenuItem("Editor Tools/Skill Editor")]
    private static void WindowBox()
    {
        //SkillSlotEditor Window = (SkillSlotEditor)GetWindow(typeof(SkillSlotEditor));
        //Window.Show();
        //�Ʒ� �� �ٰ� ���� ��
        GetWindow(typeof(SkillSlotEditor)).Show();


    }

    private Object _Object = null;
    List<Object> PrefabList = new List<Object>();

    private void Awake()
    {
        object[] Prefabs = Resources.LoadAll<GameObject>("Prefab/Object");
        for (int i = 0; i < Prefabs.Length; ++i)
        {
            PrefabList.Add((Object)Prefabs[i]);
        }
    }

    private void OnGUI()
    {
        //object[] Objects = Resources.LoadAll<Sprite>("Sprites");

        EditorGUILayout.BeginVertical();
        GUILayout.Space(10);
        GUILayout.Label("Create Skill", EditorStyles.boldLabel);
        GUILayout.Space(1);
        EditorGUILayout.EndVertical();

        EditorGUILayout.BeginHorizontal();
        GUILayout.Space(10);
        //_Object = EditorGUILayout.ObjectField("Object Prefab", _Object, typeof(GameObject), true);
        EditorGUILayout.EndHorizontal();

        EditorGUILayout.BeginHorizontal();
        EditorGUILayout.BeginVertical();

        //, GUILayout.Height(30), GUILayout.Width(50) �� �پ��� ��ư �ɼ��� ����
        Color PreColor = GUI.backgroundColor;
        GUI.backgroundColor = Color.green;

        for (int i = 0; i < PrefabList.Count; ++i)
        {
            PrefabList[i] = EditorGUILayout.ObjectField("Prefab " + i.ToString(),
                PrefabList[i], typeof(Sprite), false, GUILayout.MaxWidth(250));

            if (GUILayout.Button("Prefab" + i.ToString()))
            {

                GameObject SkillObj = Instantiate((GameObject)PrefabList[i]);
                SkillObj.transform.SetParent(GameObject.Find("Canvas_skill").transform);
                /*
                GameObject SkillObj = Instantiate((GameObject)_Object);
                SkillObj.transform.SetParent(GameObject.Find("Canvas_skill").transform);
                Image Tex = SkillObj.GetComponent<Image>();
                Tex.sprite = (Sprite)Objects[1];
                */
            }
        }

        EditorGUILayout.EndVertical();
        EditorGUILayout.EndHorizontal();
    }
}

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