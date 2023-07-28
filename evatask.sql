SELECT
    CASE WHEN s.Grade < 8 THEN 'NULL' ELSE s.Name END AS Name,
    s.Grade,
    s.Value
FROM (
    SELECT
        st.Name,
        n.Grade,
        st.Value,
        ROW_NUMBER() OVER (PARTITION BY n.Grade ORDER BY st.Name) AS name_order,
        ROW_NUMBER() OVER (ORDER BY n.Grade DESC) AS grade_order
    FROM
        Students st
    JOIN
        Notes n ON st.Value BETWEEN n.Min_Value AND n.Max_Value
) s
ORDER BY
    CASE WHEN s.Grade < 8 THEN s.Grade ELSE 0 END DESC,
    s.Grade DESC,
    s.name_order;
