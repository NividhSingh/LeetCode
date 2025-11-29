SELECT project_id
FROM Project
GROUP BY project_id
HAVING COUNT(*) = (
    SELECT COUNT(*) AS cnt
    FROM Project
    GROUP BY project_id
    ORDER BY cnt DESC
    LIMIT 1
);
