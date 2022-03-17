using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LoadData : MonoBehaviour
{
    public GameObject Parent;
    public GameObject SkillPrefab;

    //public static object[] GetLoadSprite(string _FileName)

    void Start()
    {
        object[] Objects = Resources.LoadAll<Sprite>("Sprites");

        //if (Objects == null)
            //return null;

        for (int i = 0; i < Objects.Length; ++i)
        {
            GameObject SkillObj = Instantiate(SkillPrefab);

            SkillObj.transform.SetParent(Parent.transform);
            SkillObj.transform.name = "Skill_" + i.ToString();
            Image Texture = SkillObj.GetComponent<Image>(); 
            Texture.sprite = Objects[i] as Sprite;
        }

        //return Objects;
    }
}

/*
class LoadSkillControll : MonoBehaviour
{
    void Start()
    {
        object[] Objects = LoadData.GetLoadSprite("Sprites");

        for(int i = 0; i < Objects.Length; ++i)
        {

        }
    }
}
*/